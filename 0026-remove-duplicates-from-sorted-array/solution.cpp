class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int slow = 1;
      for( int fast = 0; fast < nums.size() ; fast++ ){
        if(  nums[slow-1] != nums[fast] ){
          nums[slow] = nums[fast];
          slow = slow + 1;
        } // if
      } // for 

      return slow;
    }
};
