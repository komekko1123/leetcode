class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int k = 1; k * k <= n; k++){
            if( n % k != 0 ) continue;
            if( check_ok(nums,k)) ans += k;
            int k2 = n/k;
            if( k2 != k && check_ok(nums,k2))  ans += k2;
        }  // for  
        return ans; 
    }
    
    bool check_ok(vector<int>& nums, int k){
        int n = nums.size();
        int prevMax = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i += k){
            int drop = 0,  mn = INT_MAX, mx = INT_MIN ;
            for(int j = 0; j < k ; j++){
              int cur = nums[i+j];
              int nxt = nums[ i + (j+1) % k ];
              if( cur > nxt) drop++;
              mn = min(mn,cur);  
              mx = max(mx,cur);
            } // for
            if( drop > 1 ) return false;
            if( prevMax > mn ) return false;
            prevMax = mx;
        } // for
        return true;
    } // check_ok
};
