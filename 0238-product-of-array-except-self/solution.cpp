class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      //暴力解 + 全部相乘 然後/自己
      // 提示=算出左和右prefix
      vector<int> ans(nums.size(), 1);
      for(int i = 1; i < nums.size() ; i++ ) // 優化的
        ans[i] = nums[i-1] * ans[i-1]; // 先算左邊

      int right = 1;
      for(int i = nums.size()-1; i >= 0 ; i-- ){
        ans[i] *= right;
        right *= nums[i];
      } // for   

      return ans;
    }
};
