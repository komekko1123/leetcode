class Solution {
public:
    string reverseWords(string s) {
      istringstream iss(s);
      string token;
      vector<string> v;
      while( iss >>　token) // 從字串流 ss 中讀取內容，存入 token 中
        v.push_back(token);   
      string result;
      result=v[v.size()-1];
      for(int i =v.size()-2; i >= 0 ; i--)
        result += " " + v[i];
      return result; 
    } 
};
