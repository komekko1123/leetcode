class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      int l = 0;
      int r = nums.size() - 1;
    
      while( l < r){
        int mid = l + (r - l) / 2;
        if( nums[mid] < nums[mid+1] ){ // 在下波，旁邊上波，往右找。
          l = mid+1;
        } // if
        else { // 在上波，旁邊是下波，往左可能有上or就是上波
          r = mid;
        } // else if;
      } // while
      return l;
    }
};
