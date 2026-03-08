class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        for(int i = 0 ; i < nums.size() ; i++){
          char c = nums[i][i];
          ans += (c == '0') ? '1' : '0';
        } // for
        return ans;
    }
};
