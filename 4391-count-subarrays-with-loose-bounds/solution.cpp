class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) { // 1, 2, 3, 12 23 123
      long long ans = 0;
      long long window = 0;
      for(int i = 0 ; i < nums.size() ; i++){
        if( minK <= nums[i] && maxK >= nums[i])
          window++;
        else{
          ans +=   ( (window * (window +1) )  / 2 );
          window = 0;
        } // else
      } // for
      if( window > 0)
        ans += ( (window * (window +1) )  / 2 );
      return ans;
    }
};
