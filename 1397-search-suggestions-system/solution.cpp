class TrieNode {
public:
    TrieNode *child[26];
    string str;
    bool isWord;
    TrieNode() {
        isWord = false;
        for (auto &a : child) 
          a = nullptr;
    }
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
      TrieNode *root = new TrieNode();
      for(string ps : products){ // build trie tree
        TrieNode *temp = root;
        for( char ch : ps){
          if( temp->child[ch-'a'] == nullptr ){
            temp->child[ch-'a'] = new TrieNode();
          } // if
          temp = temp->child[ch-'a'];
        } // for
        temp->str = ps;
        temp->isWord = true;
      } // for
      
      TrieNode *temp = root;
      vector<vector<string>> ans;
      for( int i = 0; i < searchWord.size() ; i++){
        if( temp->child[searchWord[i]-'a'] == nullptr){
          while( i < searchWord.size()){
            ans.push_back({});
            i++;
          } // while
          break;
        } // if

        temp = temp->child[searchWord[i]-'a'];
        vector<string> st_arr;
        stack<TrieNode*> st;
        st.push(temp);
        while(!st.empty()){
          TrieNode *node = st.top();
          st.pop();
          for (int k = 25; k >= 0; k--) {
            if (node->child[k] != nullptr)
                st.push(node->child[k]);
          } // for
          if( node->isWord == true){
            st_arr.push_back(node->str);
            if(st_arr.size() == 3)
              break;
          } // if
        } // while
        ans.push_back(st_arr);
      } //for
      return ans;
    }
};
