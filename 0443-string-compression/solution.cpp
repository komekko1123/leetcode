class Solution {
public:
    int compress(vector<char>& chars) {
      if(chars.size() == 1)
        return chars.size();
      int left=0;
      vector<char> result;
      for(int i = 0; i < chars.size(); i++ ){
        char first = chars[left];
        char second = chars[i];
        if( first != second || i == chars.size() - 1 ){
          if( left == i - 1 ) { // 長度為1
            result.push_back(first);
            if( i == chars.size() - 1  && first != second )
              result.push_back(second);    
            else if ( i == chars.size() - 1  && first == second){
                if(first == second && i == chars.size() - 1)
                    i++;
                int remains = i - left;
                if( remains == 1 ){
                    left = i;
                    continue;
                } // if
                int curr_size = result.size();
                while( remains > 0 ){
                    char words = char(remains % 10 ) + '0'; 
                    result.insert(result.begin()+curr_size,words);
                    remains /= 10; // 往下
                } // while
            } // else if 
          } // if  
          else if( first != second || (first == second && i == chars.size() - 1) ) {
            if(first == second && i == chars.size() - 1)
              i++;
            result.push_back(first); // 先放入character
            int remains = i - left;
            if( remains == 1 ){
              left = i;
              continue;
            }
            int curr_size = result.size();
            while( remains > 0 ){
              char words = char(remains % 10 ) + '0'; 
              result.insert(result.begin()+curr_size,words);
              remains /= 10; // 往下
            } // while

            if (first != second && i == chars.size() - 1)
              result.push_back(second);
          } // else
          left = i;
        } // if
      } // for 
      
      chars = result;
      return chars.size();
    }
};
