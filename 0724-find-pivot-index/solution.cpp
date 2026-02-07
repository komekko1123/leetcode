class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      vector<int> preleft(nums.size(), 0), preright(nums.size(), 0);
      preleft[0] = nums[0];
      preright[nums.size()-1] = nums[nums.size()-1];
      for(int i = 1; i < nums.size() ; i++){
          preleft[i] +=  preleft[i-1] + nums[i];  
          preright[nums.size()-1-i] +=  preright[nums.size()-i] + nums[nums.size()-1-i];
      } // for
      
      for(int i = 0; i < nums.size() ;i++){
        if(preleft[i] == preright[i])
          return i;
      } // for
      return -1;


    }
};
