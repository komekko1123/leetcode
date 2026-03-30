class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;  
    unordered_set<int> s;
    int current;
    SmallestInfiniteSet() {
      current = 1;
    }
    
    int popSmallest() {
      if( !pq.empty() ){
        int ps = pq.top();  
        s.erase(ps);
        pq.pop();
        return ps;
      } // if
      else{
        return current++;
      } //else  
    }
    
    void addBack(int num) {
      if(s.count(num) != 1 && num < current){
        pq.push(num);
        s.insert(num);
      } // if
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
