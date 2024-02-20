class Solution {
public:
    int missingNumber(vector<int>& nums) { 
      int sums = 0;
      sums = float(nums.size() + 1) * ( float(nums.size()) / 2) ;
      for(int i = 0 ; i < nums.size() ; i++){
        sums -= nums[i];
      } // for
      return sums;
    }
};
