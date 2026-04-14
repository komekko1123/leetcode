class Solution {
public:
    int numTilings(int n) { // fn = fn-1  + fn-2 + 2(fn-3~ f0 != )>s0   f0 = 1 . f1 = 1 f2 = 2 f3 = 5
      vector<int> dp(n+2,0);
      dp[0] = 1;
      dp[1] = 1;
      dp[2] = 2;
      int mod_num = 1e9 + 7;
      for(int i = 3; i <= n ; i++){
        dp[i] = (dp[i-1] + dp[i-2] ) % mod_num;
        for(int j = 0 ; j <= i - 3 ; j++ ){ // SN-2 > fn-3 ~-0
          dp[i] =  ( dp[i] + dp[j] ) % mod_num;
          dp[i] =  ( dp[i] + dp[j] ) % mod_num;          
        } // for
      } // for

      return dp[n];
    }
};
