class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long result = ( (nums.size() - 1 ) * nums.size() ) / 2 ; // 總合= n*n+1 /2 - n
        unordered_map<int,int> uMap; // i = nums[i] - i
        for( int i = 0 ; i < nums.size() ; i++ ){
          long long gp = nums[i] - i;
          uMap[gp]++;
          result -= uMap[gp] - 1 ;
        } // for

      return result;
    }
};


