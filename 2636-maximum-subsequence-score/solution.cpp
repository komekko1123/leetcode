class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
       vector<pair<int,int>> vp;
       for(int i = 0; i < nums1.size() ; i++){
         vp.push_back({nums2[i],nums1[i]});
       } // for

       sort(vp.rbegin(), vp.rend());
       priority_queue<int, vector<int>, greater<int> > pq;
       long long ans = 0;
       long long sw = 0;
       for(int i = 0; i < vp.size(); i++){
         int vp_f = vp[i].first; // num2
         int vp_s = vp[i].second; // num1        
         pq.push(vp_s);
         sw += vp[i].second;
         if( pq.size() > k){
           sw = sw - pq.top();
           pq.pop();            
         } // if 
         
          if( pq.size() == k ){
            long long temp = sw * vp_f;
            ans = max(ans, temp); 
          } // if 

       } // for
       return ans;
    }
};
