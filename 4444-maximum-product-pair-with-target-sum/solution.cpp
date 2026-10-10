class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
      unordered_map<int,int> um;
      for(int i = 0 ; i < nums.size() ;i++){
        if( um.count(nums[i]) == 0)
          um[nums[i]] = i;    
      } // for
        
      sort(nums.begin(),nums.end());
      int left = 0,right = nums.size()-1;
      vector<int> ans = {-1,-1};
      int product = -INT_MAX;
      while(left < right){
        if( (nums[left] + nums[right]) > target){ // 太大
          right--;
        } // if 
        else if( (nums[left] + nums[right]) < target){ // 太小
          left++;
        } // else if 
        else if( ( ( nums[left] + nums[right]) == target ) && nums[left] == nums[right]){ // 可以是解，但倆著相等
          left++;
        } // else if           
        else if( (nums[left] + nums[right]) == target){ // 解
          int temp_product = nums[left] * nums[right];
          if( temp_product > product ){
            product = temp_product;
            ans = {um[nums[right]],um[nums[left]]};
          } // if
          left++;
          right--;
        } // else if           
      } // while
      return ans;
        
    }
};
