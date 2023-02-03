class Solution {
    public:
    string convert(string s, int numRows) {
      if ( numRows == 1 || s.length() == 1 )
        return s;
      int row = 0, column = 0, i = 0 ;
      string ans;  
      vector<string> LR(numRows, ""); 
      for( i = 0 ; i < s.length() ; i++ ){
        if ( column != numRows){
          LR[row] = LR[row] + s[i];
          row++;
          column++;
        } // if
        else if( column == numRows ){
          row = row - 2;
          column = column - 2 ;
          while( i < s.length() && column > 0  ){
            LR[row] += s[i];
            row--;
            column--;
            i++;
          } // while 
          if ( column == 0 )
            i--;
        } // else if 
      } // for
      
      for( i = 0 ; i < numRows ; i++)
        ans += LR[i];
      return ans;
    } // convert
};
