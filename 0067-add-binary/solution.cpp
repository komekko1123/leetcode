class Solution {
public:
    string addBinary(string a, string b) {
      string ans;
      int carry = 0;
      int n = a.size(), m = b.size();
      int i = n-1, j = m-1;
      for( i = a.size() - 1 , j = b.size() - 1 ; i>=0 || j>=0 ;) {
          int sum = carry;
          if(i >= 0) sum += a[i--] - '0';
          if(j >= 0) sum += b[j--] - '0';
          carry = sum > 1 ? 1 : 0;
          ans = char(sum%2 + '0') + ans;
         
      }
      if(carry == 1)
        ans = '1' + ans;
      return ans;
  }
};
