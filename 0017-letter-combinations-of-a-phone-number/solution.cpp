class Solution {
public:
    vector<string> ans;
    unordered_map<char,string> gum;
    string gdigits;
    vector<string> letterCombinations(string digits) {
      unordered_map<char,string> um;
      um['2'] = "abc";  
      um['3'] = "def";    
      um['4'] = "ghi";    
      um['5'] = "jkl";  
      um['6'] = "mno";    
      um['7'] = "pqrs";          
      um['8'] = "tuv";  
      um['9'] = "wxyz";
      gum = um;
      gdigits = digits;
      dfs( 0,"" );
      return ans;
    }

    void dfs(int index,string s ){
      if( s.size() == gdigits.size() ){
        ans.push_back(s);
        return;
      } // if

      for(char a : gum[gdigits[index]]){
        s += a;
        dfs(index+1,s);
        s.pop_back();
      } // for
    } // dfs
};
