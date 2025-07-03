class Solution {
public:
    char kthCharacter(int k) {
      string str = "a";
      for( int b = 1 ; b < k   ; b = b*2 ){
        string temp;
        for( char c : str){
          if( c == 'z' )
            c = 'a';
          else
            c = c + 1;
          temp = temp + c;
        } // for
        str = str + temp; 
      } // for  
      return str[k-1];
    }
};
