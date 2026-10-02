class Trie {
public:

struct Node {
    bool isEnd;
    vector<Node*> children;

    Node() {
        isEnd = false;
        children = vector<Node*>(26, nullptr);
    }
};

    Node *root;

    Trie() {
      root = new Node();
    }
    
    void insert(string word) {
      Node *temp = root;
      for(char c : word){
        if( temp->children[c-'a'] == nullptr)
          temp->children[c-'a'] = new Node();
        temp = temp ->children[c-'a'];
      } // for
      temp->isEnd = true;
    }
    
    bool search(string word) {
      Node *temp = root;
      for(char c : word){
        if(temp->children[c-'a'] == nullptr)
          return false;
        temp = temp ->children[c-'a'];
      } // for 
      if(temp->isEnd == true)
        return true;
      else
        return false;
    }
    
    bool startsWith(string prefix) {
      Node *temp = root;
      for(char c : prefix){
        if(temp->children[c-'a'] == nullptr)
          return false;
        temp = temp ->children[c-'a'];
      } // for 
      return true;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
