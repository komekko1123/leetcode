class Solution {
public:
    int majorityElement(vector<int>& nums) {
      unordered_map<int,int> um;
      for(int n:nums){
        um[n]++;
      } // if

      int count = -1;
      int ele = -1;
      for(auto it = um.begin() ; it != um.end() ; it++){
        if(it->second > count ){
          ele = it->first;
          count = it->second;
        } // if
      } // for
      return ele;
    }
};
