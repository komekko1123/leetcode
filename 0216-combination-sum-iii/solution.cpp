class Solution {
public:
    vector<vector<int>> us;
    set<int> vs;
    vector<vector<int>> combinationSum3(int k, int n) {
      dfs(n,k);  
      return us;
    }

    void dfs(int target,int k){
      if( k == 0 && target == 0 ){
        vector<int> temp(vs.begin(),vs.end());
        for (auto it = us.begin(); it != us.end(); it++) {
            if (*it == temp)
              return;
        } // for

        us.push_back(temp);
        return;
      } // if

      if( k <= 0 || target <= 0 )
        return;
      
      for(int i = 1; i < 10 ; i++){
        if( count(vs.begin(),vs.end(), i) == 1)
          continue;
        vs.insert(i);
        dfs(target-i,k-1);
        vs.erase(i);
      } // for

    } // dfs
};
