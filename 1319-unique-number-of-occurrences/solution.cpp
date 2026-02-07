class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      unordered_map <int,int> mp;
      unordered_set <int> st;
      for(int a: arr){
        mp[a]++;  
      } // for

      for(auto it = mp.begin() ; it != mp.end() ; it++ ){
        if( st.count(it->second) == 1  ){
          return false;
        } // if
        st.insert( it->second);
      } // for

      return true;
    }
};
