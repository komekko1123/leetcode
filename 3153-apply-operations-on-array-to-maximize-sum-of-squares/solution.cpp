class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
      const long long MOD = 1e9 + 7;
      vector<int> cnt(32,0);
      for(int x: nums){
        for(int i = 0 ; i < 32 ; i++){
          int right = x & 1;
          cnt[i] += right;
          x >>= 1;
        } // for
      } // for    



      long long ans = 0;
      for(int i = 0 ; i < k ; i++){
        long long n = 0;
        int temp = 1;
        for(int j = 0 ; j < 32 ; j++){
          if( cnt[j] > 0 ){
            cnt[j]--;
            n += temp;
          } // if
          temp <<= 1;
        } // for
        ans = (ans + (n * n) ) % MOD;  
      } // for
      return ans;
    }
};
