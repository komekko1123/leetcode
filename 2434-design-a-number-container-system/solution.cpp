class NumberContainers {
public:
    unordered_map<int,set<int>> mMap; // number->index set
    unordered_map<int,int> mMapIndex;  // index -> number
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
      if ( mMapIndex.find(index) != mMapIndex.end()  ){ // find the index it means replace
        int oldnum = mMapIndex[index];
        mMap[oldnum].erase(index);
        if ( mMap[oldnum].size() == 0 )
          mMap.erase(oldnum);  
        mMapIndex[index] = number;
        mMap[number].insert(index);
      } // if

      else { // mean add into the map
        mMap[number].insert(index);
        mMapIndex[index] = number;
      } // else
    }
    
    int find(int number) {
        if ( ! mMap[number].empty() )
          return *mMap[number].begin();
        else
          return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
