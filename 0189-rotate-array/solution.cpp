class Solution {
public:
    void rotate(vector<int>& nums, int k) { // 第一想到暴力法，按照k去loop，第二也是loop，但用兩個指標。看到提示了，寫翻轉法
      int n = nums.size();
      if( k > n) k = k % n;
      for(int i = 0 ; i < nums.size() ; i++){
        if( i < (n - k) / 2 )
          swap(nums[i], nums[n-k-i-1]);
        if( i < k / 2)
          swap(nums[n-k+i], nums[n-i-1]); 
      } // for
      reverse(nums.begin(), nums.end());
    }
};
