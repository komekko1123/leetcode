class Solution {
public:
    int m,n;
    long long dfs(vector<vector<int>>& grid, int i, int j){
      if( i >= n || i < 0 || j >= m || j < 0)
        return 0;
      if( grid[i][j] == 0)
        return 0;
      long long current = grid[i][j];
      grid[i][j] = 0;
      long long left =  dfs(grid, i, j-1);
      long long right = dfs(grid, i, j+1);
      long long up =    dfs(grid, i-1, j);
      long long down =  dfs(grid, i+1, j);
      long long total = current + left + right + up + down ;
      return total;
    } // if
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if( grid[i][j] > 0){ // 找到island
                   if( dfs(grid,i,j) % k == 0)
                     ans++;
                } // if
            } //for
        } // for
        return ans;
    }
};
