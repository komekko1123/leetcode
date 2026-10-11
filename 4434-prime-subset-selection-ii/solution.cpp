class Solution {
public:
    vector<int> maxPrimeSubset(int n, int s) {
        if( s <= 1)
          return {};
        vector<int> prime_arr;
        vector<bool> isPrime(n+1,false);
        vector<int> ans;        
        for(int i = 2 ; i <= n && i <= s ; i++){ //建質數表
          if( isPrime[i] == false){
            prime_arr.push_back(i);
            if((long long) i * i <= n){
              for(int j = i * i ; j <= n ; j = j + i){
                isPrime[j] = true;    
              } // if  
            } // if 
          } // if
        } // for 

        int total = accumulate(prime_arr.begin(), prime_arr.end(), 0);
        const int INF = INT_MAX >> 1;
        vector<vector<int>> dp(prime_arr.size()+1,vector<int>(total+1,INF)); // n arr
        dp[prime_arr.size()][0] = 0;
        for(int i = prime_arr.size() - 1 ; i >= 0 ; i--){
            int x = prime_arr[i];
            for(int j = 0; j <= total; j++){
              dp[i][j] = dp[i+1][j]; // 不選
              if( j >= x && dp[i+1][j-x] != INF) // 選
                dp[i][j] = min(dp[i][j],dp[i+1][j-x] + 1);
            } // for
        } // for

        int bestSum = 0;
        for (int j = 1; j <= total; j++) {
            if (dp[0][j] == INF) continue;
    
            long long diff = abs((long long)j - s);
            long long bestDiff = abs((long long)bestSum - s);
    
            if (diff < bestDiff || 
                (diff == bestDiff && dp[0][j] < dp[0][bestSum]) ) {
                bestSum = j;
            }
        }
    
        // 往回找實際選到的元素
        int remain = bestSum;
    
        for (int i = 0; i < prime_arr.size(); i++) {
            int x = prime_arr[i];
            
            if (remain >= x &&
                dp[i + 1][remain - x] != INF &&
                dp[i][remain] == dp[i + 1][remain - x] + 1) {
                ans.push_back(x);
                remain -= x;
            }
        }
        return ans;    
    }
};
