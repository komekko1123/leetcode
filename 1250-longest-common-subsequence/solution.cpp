class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
      int ans = 0, n1 = text1.size() , n2 = text2.size();
      vector<int> v1(n2+1,0);
      vector<vector<int>> dp(n1+1,v1);
      for(int i = 1; i <= n1 ; i++){
        for(int j = 1; j <= n2 ; j++){
          if( text1[i-1] == text2[j-1] ){
            dp[i][j] = dp[i-1][j-1]+1;  
          } // if
          else{
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
          } // else
        } // for
      } // for
      ans = dp[n1][n2];
      return ans;  
    }
};
