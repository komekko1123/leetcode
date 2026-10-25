class Solution {
public:
    int m,n;
    void dfs(vector<vector<int>>& grid, int i, int j){
        if (i < 0 || i >= m || j < 0 || j >= n) // 過邊界
            return;
        if (grid[i][j] == 1) // 走到水地
            return;
        grid[i][j] = 1; // visited
        dfs(grid, i - 1, j);  // up
        dfs(grid, i + 1, j);  // down
        dfs(grid, i, j - 1);  // left
        dfs(grid, i, j + 1);  // right          
    } // dfs
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();        
        int ans = 0;
        for(int i = 0 ; i < m ; i++){ // (左到右) 上 ，下
          if( grid[i][0] == 0) dfs(grid, i, 0); //上
          if (grid[i][n - 1] == 0)  dfs(grid, i, n - 1); //下
        } // for

        for(int j = 0 ; j < m ; j++){ // (上到下) 左 ，右
          if( grid[0][j] == 0) dfs(grid, 0, j); //上
          if (grid[m-1][j] == 0)  dfs(grid, m-1, j); //下
        } // for

        for(int i = 1 ; i < m - 1 ; i++){
            for(int j = 1; j < n - 1 ; j++){
              if( grid[i][j] == 0 ){
                ans++;
                dfs(grid,i,j);
              } // if
            } // for
        } // for
        return ans;
    }
};
