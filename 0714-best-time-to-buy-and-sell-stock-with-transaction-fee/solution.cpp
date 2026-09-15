class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
      if( prices.size() == 1 )
        return 0;
      int cash = 0, hold = -prices[0]; // cash 第i天沒有股票的利潤，hold 有
      for(int i = 1 ; i < prices.size(); i++){
        cash = max(cash, prices[i] - fee + hold);  
        hold = max(hold, cash-prices[i] );  
      } // for
      return max(cash, hold);
    }
};
