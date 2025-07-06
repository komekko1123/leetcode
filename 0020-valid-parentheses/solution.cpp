class Solution {
public:
    bool isValid(string s) {
      stack<char> st;
      for(char c: s){
        if( c == '{' || c == '(' || c == '[')
          st.push(c);
        else if ( st.size() > 0) {
          if( (c == '}' && st.top() != '{') || (c == ')' && st.top() != '(') || (c == ']' && st.top() != '[')  ){
            return false;
          } // if
          else
            st.pop();
        } // else
        else // pop empty stack
          return false;  
      } // for
      
      if( st.size() > 0)
        return false;
      else
        return true;
    }
};
