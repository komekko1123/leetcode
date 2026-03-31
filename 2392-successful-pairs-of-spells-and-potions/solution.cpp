class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

      sort(potions.begin(),potions.end());
      for(int i = 0; i < spells.size() ; i++){
        int l = 0;
        int r = potions.size()-1;
        int pos = potions.size();
        while( l <= r){
          int mid = l + (r-l) / 2;
          if( 1LL * spells[i]  * potions[mid] >= success){ // 太大往左
            r = mid-1;
            pos = mid;
          } // if
          else if( 1LL * spells[i]  * potions[mid] < success) // r
            l = mid+1;
        } // while
        spells[i] = potions.size()-pos;
      } // for
      return spells;
    }


    // vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    //   int sum = 0;
    //   vector<double> pp;
    //   for(int i = 0 ; i < potions.size() ; i++ ){
    //     pp.push_back( double( success) / potions[i]);
    //   } // for    
    //   sort(pp.begin(), pp.end(), greater<double>());
    //   for(int i = 0; i < spells.size(); i++){
    //     for(int j = 0; j < pp.size(); j++){
    //       if(spells[i] < pp[j] && j == pp.size() -1){
    //         spells[i] = 0;
    //         break;
    //       } // if 
    //       else if( spells[i] < pp[j])
    //         continue;
    //       spells[i] = (pp.size()-j );
    //       break;
    //     } // for
    //   } // for
    //   return spells;
    // }

};
