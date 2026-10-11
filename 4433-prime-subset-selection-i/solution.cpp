class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        if( s <= 1)
          return {};
        vector<int> ans;
        vector<bool> isPrime(n+1,false);
        for(int i = 2 ; i <= n ; i++){
          if( isPrime[i] == false){
            s = s - i;
            if( s < 0)
              break;
            ans.push_back(i);
            if( s <= i )
              break;
            if((long long) i * i <= n){
              for(int j = i * i ; j <= n ; j = j + i){
                isPrime[j] = true;    
              } // if  
            } // if 
          } // if
        } // for 
        return ans;
    }
};
