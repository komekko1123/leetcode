class Solution {
public:
    bool canJump(vector<int>& nums) {
      int mr = 0;
      for(int i = 0 ; i < nums.size() ;i++){
        if( i > mr) return false;  
        mr = max(mr, i+nums[i]);
      } // for 
      return true;
    }
};
