class Solution {
public:
    int minFlips(int a, int b, int c) {
      int ans = 0;
      while( a > 0 || b > 0 || c > 0 ){
        int a_, b_, c_;
        a_ = a & 1;
        a >>= 1;
        b_ = b & 1;
        b >>= 1;
        c_ = c & 1;
        c >>= 1;    
        if( c_ == 0){
          if( a_ == 1 && b_ == 1)
            ans = ans + 2;            
          else if( a_ == 0 && b_ == 0)
            ans += 0;
          else
            ans += 1;
        } // if

        else{ // c = 1 
          if( a_ == 0 && b_ == 0 )
            ans = ans + 1;            
        } // else
      } // while
      return ans;

    }
};
