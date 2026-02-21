class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
      if( grid.size() == 1)
        return 1;
      int result = 0;
      vector<vector<int>> edges;    
      for(int i = 0; i < grid[0].size() ; i++){
        vector<int> e;
        e.clear();  
        for(int j = 0; j < grid[0].size(); j++){
          e.push_back(grid[j][i]);
        } // for
        edges.push_back(e);
      } // for
      
      for( auto row : grid){
        for( auto column: edges){
          if(row == column){
            result++;
          }// if
        } // for
      } // for
      
      return result;
    }
};
