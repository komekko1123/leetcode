class Solution {
public:
    bool closeStrings(string word1, string word2) {  // 沒想法的一題
      if( word1.size() != word2.size() )
        return false;
      unordered_map <char,int> mp; //str1
      unordered_map <char,int> mp2; //str2

      unordered_map <int,int> mp3; //1的次數
      unordered_map <int,int> mp4; //2的次數
      for(char c: word1)
        mp[c]++;
      for(char c: word2)
        mp2[c]++;
      for(auto& p : mp){
        if( mp2.count(p.first) == 0 ) // op1要可以swap, 所以字母要相互存在
          return false;
        mp3[p.second]++;
      } // for
      for(auto &p : mp2)
        mp4[p.second]++;
      for(auto &p : mp3){
        if( mp4[p.first] != p.second ) // op2次數要相同
          return false;  
      } // for
      return true;
    }
};
