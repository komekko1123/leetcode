class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int &a, const int &b){
          return abs(a) < abs(b);
        }); 
        long long ans = 0;
        int left = 0,right = nums.size()-1;
        while(left <= right){
          if( left == right){
            ans += nums[left] * nums[left];
            left++;
            continue;
          } // if
          int left_a = nums[left] * nums[left];
          int right_a = nums[right] * nums[right];
          ans += (right_a - left_a);
          left++;
          right--;
        } // while
        return ans;
    }
};
