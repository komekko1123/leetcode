class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vs;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(),candidates.end());
      backtracking(target,0, 0,candidates);
      return ans;
    }

    void backtracking(int target,int start, int current, vector<int> &s){
      if(target == 0){
        ans.push_back(vs);
        return;
      } // if
      else if( target < 0 )
        return;
      
      for(int i = start ; i < s.size() ; i++){
        if( i > start && s[i] == s[i-1]  )
          continue;
        vs.push_back(s[i]);
        backtracking(target-s[i],i+1, i,s);
        vs.pop_back();
      } // for

    } //backtracking       
};
