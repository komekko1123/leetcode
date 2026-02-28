class Solution {
public:
    int concatenatedBinary(int n) {
      long long ans = 0;
      int len = 0;
      int modulenum = 1000000007;
      for (int i = 1; i <= n; i++) {
        if ((i & (i - 1)) == 0) 
          len++;
          ans = ((ans << len) + i) % modulenum;
        }
        return (int)ans;
    }
};
