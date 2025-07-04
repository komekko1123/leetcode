class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      string str; 
      sort(strs.begin(), strs.end());
      str = strs[0];
      string str_lar = strs.back();
      string ans;
      for(int i = 0; i < str.size()  ; i++){
        if( str[i] == str_lar[i] )
          ans += str[i];
        else
          break;
      } // for
      return ans;
    }
};
