class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
      vector<int> ans;
      int left = 0, right = 0;
      for(int i = 0; i < nums.size() ; i++){
        if( nums[i] < target){
          left++;
          for(int &j : ans){
            j++;
          }  // for
        } // if
        else if( nums[i] == target){
          ans.push_back(left + right);
          right++;
        } // else if
      } // for
      return ans;
    }
};
