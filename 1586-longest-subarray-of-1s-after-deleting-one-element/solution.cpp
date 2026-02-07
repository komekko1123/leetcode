class Solution {
public:
    int longestSubarray(vector<int>& nums) {
      int left = 0, ans = 0, z_count = 0;
      for( int right = 0 ; right < nums.size() ; right++  ){
        if( nums[right] == 0 )
          z_count++;
        while( z_count > 1 ){
            if( nums[left] == 0 )
              z_count--;
            left++;
        } // while
        ans = max(ans, right-left+1);
      } // for 
      return ans-1;
    }
};
