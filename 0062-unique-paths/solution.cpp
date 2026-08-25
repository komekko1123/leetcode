class Solution {
public:
    int uniquePaths(int m, int n) {
       vector<int> v(n,0);
       vector<vector<int>> dp(m,v);
       dp[0][0] = 1;
       int top = 0, left = 0;
       for(int i = 0 ; i < m ; i++){
         for(int j = 0 ; j < n ; j++){
            if( i == 0 && j == 0 )
              continue;
            if( i > 0)
              top = dp[i-1][j];
            else
              top = 0;
            if( j > 0 )
              left = dp[i][j-1]; 
            else 
              left = 0;
            dp[i][j] =  top + left;
         } // for
       } // for
       return dp[m-1][n-1]; 
    }
};
