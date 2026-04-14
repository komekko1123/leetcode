class Solution {
public:
    vector<int> memo;
    int combinationSum4(vector<int>& nums, int target) { // backtracking會tle，要用mem or dp
      memo.assign(target+1,-1); // assign ~= 初始化
      return dfs(nums,target);
    }

    int dfs(vector<int>& nums, int target){
      if( target == 0  ){
        return 1;
      } // if
        
      else if( target < 0)
        return 0;
      
      if( memo[target] != -1 )
        return memo[target];

      int ways = 0;
      for(int i = 0; i < nums.size() ; i++){
        ways += dfs(nums,target-nums[i]);
      } // for
      
      memo[target] = ways;
      return ways;
    } // backtracking
};
