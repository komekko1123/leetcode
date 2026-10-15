class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int count = 0;
        set<int> ss;
        for(int i = 0 ; i <= nums.size() ; i++){
          set<int> ss;
          for(int j = i ; j < nums.size() ; j++ ){
            ss.insert(nums[j]);            
            count += (ss.size() * ss.size());
          } // for
        } // for
        return count;
    }
};
