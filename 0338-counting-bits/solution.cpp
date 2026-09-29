class Solution {
public:
    vector<int> countBits(int n) {
        if( n == 0)
          return {0};
        else if( n == 1)
          return {0,1};
        vector<int> ans = {1};
        vector<int> ans_temp = {0,1};
        for(int i = 1; i < n ; i = (i << 1) + 1 ){
          if( ( i << 1 ) + 1 <= n){
            vector<int> temp = ans;            
            for(int &x : temp )
              x++;
            ans.insert(ans.end(), temp.begin(), temp.end());        
            ans_temp.insert(ans_temp.end(), ans.begin(), ans.end());  
          } // if
          else{
            vector<int> temp = ans;
            n = n - i;
            if( n >temp.size() ){
              ans_temp.insert(ans_temp.end(), ans.begin(), ans.end());  
              n = n - temp.size();
              for(int &x : temp )
                x++;  
            } // if          

            for(int j = 0; j < n ; j++)
              ans_temp.push_back(temp[j]);
          } // else
        } // for

        return ans_temp;
    }
};
