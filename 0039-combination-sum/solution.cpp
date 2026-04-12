class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vs;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      int start = 0;
      // sort(candidates.begin(),candidates.end());
      backtracking(target,start,candidates);
      return ans;
    }

    void backtracking(int target,int start,vector<int> &s){
      if(target == 0){
        ans.push_back(vs);
        return;
      } // if
      else if( target < 0 )
        return;
      
      for(int i = start ; i < s.size() ; i++){
        vs.push_back(s[i]);
        backtracking(target-s[i],i,s);
        vs.pop_back();
      } // for

    } //backtracking
};
