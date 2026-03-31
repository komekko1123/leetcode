class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
      int speed = 0; // speed  
      int l = 1;
      int r = *max_element(piles.begin(), piles.end());
      while( l <= r){
        int mid = l + ( r - l ) / 2;
        if( isOk(piles, h, mid) == true ) {// ok能在時間內吃完 那就往左看能不能更慢
          speed = mid;
          r = mid-1;
        } // if
        else{ // 代表時間不夠，要更多時間
          l = mid+1;
        } // else
      } // while
      return l;
       
    }

    bool isOk(vector<int>& piles, int &h, int &speed){
      long long hr =0;
      for(int i = 0; i < piles.size(); i++){
        hr += ( piles[i] + speed - 1 ) / speed; // 需要幾小時 = ceil(piles[i] / speed )
      } // for
      return hr <= h;
    } // isOk
};
