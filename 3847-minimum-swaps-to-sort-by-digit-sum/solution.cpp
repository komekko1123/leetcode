class Solution {
public:
    int minSwaps(vector<int>& nums) {
      int n = nums.size();
      vector<array<int,3>> v ;
      for(int i = 0 ; i < nums.size() ; i++){
        int sum_a = 0, nb = nums[i];
        for(  ; nb > 0 ; nb /= 10)  sum_a += nb%10;  
        v.push_back({sum_a,nums[i],i});
      } // for

      sort(v.begin(), v.end());
      vector<bool> vis(n, false);
      int ans = 0;
      for(int i = 0 ; i < nums.size() ; i++){
        if( vis[i]) continue;
        int len = 0, j = i;
        while( ! vis[j]){
          vis[j] = true;
          j = v[j][2];
          len++;
        } // while
        ans += len - 1;
      } // for
      return ans;
    }
};
