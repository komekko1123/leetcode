class Solution {
public:
    int minDistance(string word1, string word2) { // dp 三個舉動,i,d,r
      int m = word1.size(), n = word2.size();
      vector<vector<int>> dp(m + 1, vector<int>(n + 1));
      for(int i = 0 ; i <= m ; i++){
        dp[i][0] = i; 
      } // for
      for(int j = 0 ; j <= n ; j++){
        dp[0][j] = j; 
      } // for

      for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
          if( word1[i-1] == word2[j-1])
            dp[i][j] = dp[i-1][j-1];    // 左上，不用動作兩者相同，上一步
          else
            dp[i][j] = min( { dp[i-1][j-1], dp[i][j-1] , dp[i-1][j] } ) + 1 ;  // 取代
        } // for
      } // for
      return dp[m][n];
    }
};
