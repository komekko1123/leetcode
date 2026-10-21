class Solution {
public:
    bool isHappy(int n) {
      unordered_set<int> hashset;
      int temp = 0;
      
      while( n != 1){
        int next = 0;
        if( hashset.count(n) == 1)
          return false;
        hashset.insert(n);          
        while( n > 0  ){
            temp = n % 10;
            next += temp * temp;
            n = n / 10;
        } // for
        n = next;
      } // while
      return true;
    }
};
