class RecentCounter {
public:
    queue<int> request;
    RecentCounter() {
 
    }
    
    int ping(int t) {
      while( !request.empty() ){
        if( 3000 + request.front() - t < 0 )
          request.pop();
        else
         break;
      } // for
      request.push(t);
      return request.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
