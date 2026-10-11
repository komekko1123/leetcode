class Solution {
public:
    bool threeFibonacciSum(int n) {
      int sum = 0,n1 = 0,n2 = 1;
      vector<int> dp = {0,1,1};
      if( n < 2 )
        return false;
      for(int i = 2 ; i < 100000 ; i++){
        int next = dp[i]+ dp[i-1];
        if( (sum + next) == n)
          return true;
        else if( (sum + next) > n)
          break;
        else
          dp.push_back(next);
        sum = dp[i-1];
      } // for
      return false;
    }
};
