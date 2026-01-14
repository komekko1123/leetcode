class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if( nums.size() <= 2)
          return false;
        int left = INT_MAX, right = INT_MAX;
        for(int i = 0; i < nums.size() ; i++){
          if( nums[i] <= left)
            left = nums[i]; // 找到最小的
          else if( nums[i] <= right  )
            right = nums[i]; // 找到次大的
          else
            return true;
        } // for
        return false;
    }
};
