class StockSpanner {
public:
    stack<int> st;
    vector<int> ans;
    StockSpanner() {    
    }
    
    int next(int price) {
      if( st.empty() ){
       st.push(price);
       ans.push_back(1);
       return 1;
      } // if
      int count = 1;
      int n = ans.size() - 1;
      while( !st.empty() && price >= st.top()){
        count += ans[n];
        n -= ans[n];
        st.pop();
      } // while
      st.push(price);
      ans.push_back(count);
      return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
