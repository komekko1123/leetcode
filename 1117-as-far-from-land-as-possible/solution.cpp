class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
      int i = 0, j = 0;
      int column = grid[0].size();
      int row = grid.size();
      vector<int> dx={0,0,1,-1};
      vector<int> dy={1,-1,0,0};
      queue<pair<int,int>> q,next_q;
      for( i = 0 ; i < row ; i++ ){
        for( j = 0 ; j < column ; j++) {
          if( grid[i][j] == 1 )
            q.push({i,j});
            // 做標記grid[i][j] = 2;
        } // for
      } // for
    
      if( q.size() == row * column )
        return -1;
      int distance = -1;
      while( ! q.empty()){
        pair <int,int> temp_q = q.front();
        q.pop();
        for( i = 0 ; i < 4 ; i++  ){
          int next_x = temp_q.first + dx[i];  
          int next_y = temp_q.second + dy[i];
          if ( next_x < 0 || next_y < 0 || next_x >= column || next_y >= row || grid[next_x][next_y] == 1  ) // 超過(不符)範圍或是已是陸地
            continue;
          else { // grid[next_x][next_y] == 0 的狀況 (沒走過水滴的狀況)
            grid[next_x][next_y] = 1; // 標記已走過
            next_q.push({next_x,next_y});
          } // else
        } // for
        if( q.empty() ){
          swap(q,next_q); // 交換成下個queue 同時也會清空下個queue
          distance++; // 代表走過一輪
        } // if
      } // while
      return distance;
    }
};
