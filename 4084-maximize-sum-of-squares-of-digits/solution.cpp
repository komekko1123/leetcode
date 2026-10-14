class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
      string ans;
      for( ; num > 0; num--){
        if( sum > 9 ){
          ans += "9";
          sum = sum - 9;
        } // if

        else if( 0 < sum && sum <= 9 ){
          int remain = sum % 10;
          sum = sum - remain;
          char ch = '0' + remain;
          ans += ch;
        } // else if

        else 
          ans += "0";
      } // for
      if( sum > 0)
        return "";
      else 
        return ans;
    }
};
