class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      int ans = 0;
      unordered_set<int> us;
      stack<int> st;
      for(int i = 0 ; i < isConnected.size() ; i++ ){
        if( us.count(i) == 0){
          st.push(i);
          us.insert(i);
        } // if
        else
          continue;
        while( !st.empty()){
          int j = st.top();
          st.pop();
          for(int k = 0 ; k < isConnected.size() ; k++){
            if( isConnected[j][k] == 1 && j != k && us.count(k) == 0){
              st.push(k);
              us.insert(k);
            } // if
          } // for
        } // while
        ans++;
      } //for 
      return ans;
    }
};
