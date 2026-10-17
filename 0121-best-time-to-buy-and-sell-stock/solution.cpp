class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int sum = 0, left = prices[0];
      for(int i = 1; i < prices.size() ; i++){
        if( left > prices[i]){
          left = prices[i];
        } // if
        else if( left < prices[i]){
          sum = max(sum, prices[i] - left);
        } // else if
      } // for
      return sum;
    }
};
