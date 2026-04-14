class Solution {
public:
    int rob(vector<int>& nums) {
      vector<int> dp(nums.size()+2,0);
      for(int i = 0; i < nums.size(); i++){
        dp[i+2] = max( dp[i] + nums[i] , dp[i+1]);
      } // for
      
      return max(dp[nums.size()+1], dp[nums.size()]);    
    }
};
