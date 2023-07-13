class Solution {
public:
    bool isPalindrome(int x) {
      if( x < 0 || ( x != 0 && x%10 == 0 )  )
        return false;
      int rem = 0;
      while( x > rem){
        rem = rem *10 + x%10;
        x /= 10;
      } // while

      if( x== rem || ( x == rem / 10) ) // 偶與奇數 奇數(把中間去除所以除10)
        return true;
      else 
        return false;
    }
};


