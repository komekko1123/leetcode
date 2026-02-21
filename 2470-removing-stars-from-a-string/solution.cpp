class Solution {
public:
    string removeStars(string s) {
      vector<char> st;
      for(int i = 0 ; i < s.size() ;i++ ){
        if(s[i] == '*')
          st.pop_back();
        else
          st.push_back(s[i]);
      } // for
      
      string ans;
      for(char c : st){
        ans += c;
      } // for

      return ans;
    }
};
