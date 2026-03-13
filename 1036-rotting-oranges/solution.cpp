class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int freshorange = 0;
      vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
      queue<pair<int,int>> qu;
      for(int i = 0 ; i < grid.size() ; i++){
        for(int j = 0; j < grid[i].size() ; j++ ){
          if( grid[i][j] == 1)
            freshorange++;
          else if( grid[i][j] == 2){
            qu.push({i,j});
          } // else if
        } // for
      } // for
     
      int step = 0;
      while( !qu.empty() ){
        int sz = qu.size();
        while( sz--){
          int x = qu.front().first;
          int y = qu.front().second;
          qu.pop();
          for(int i = 0 ; i < 4 ; i++){
            int dx = x + dir[i].first;
            int dy = y + dir[i].second;
            if( dx < 0 || dx >= grid.size() || dy < 0 || dy >= grid[0].size() ) //非法的話
              continue;
            if( grid[dx][dy] == 0 || grid[dx][dy] == 2)
              continue;
            qu.push({dx,dy});
            grid[dx][dy] = 2; // 代表是新鮮的
            freshorange--;
            if( freshorange == 0 )
              return step+1;
          } // for 
        } // while
        step++;
      } // while

      return ( freshorange > 0 ) ? -1 : 0 ;
    }
};
