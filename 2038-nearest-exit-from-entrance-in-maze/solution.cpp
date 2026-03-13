class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
      vector<vector<bool>> visited;
      for(auto &c : maze){
        vector<bool> vi;
        for( auto &ch : c){
          if( ch == '+')
            vi.push_back(true);
          else
            vi.push_back(false);
        } // for
        visited.push_back(vi);
      } // for

      return bfs(maze, visited, entrance);
    }

    int bfs(vector<vector<char>>& maze, vector<vector<bool>> &visited, vector<int>& entrance) {
      queue<vector<int>> q;
      q.push(entrance);
      vector<int> dx = {1,-1,0,0};
      vector<int> dy = {0,0,1,-1};
      int ans = 0;
      while(!q.empty()){
        int n = q.size();
        ans++;
        for(int i = 0 ; i < n ; i++){
            vector<int> e = q.front();
            q.pop();
            if( visited[e[0]][e[1]])
              continue;
            visited[e[0]][e[1]] = true;
            for(int d = 0 ; d < 4 ; d++){
                int nx = e[0] + dx[d];
                int ny = e[1] + dy[d];
                if( nx >= 0 && nx < maze.size() && ny >= 0 && ny < maze[0].size() ){ // 合法範圍 
                  if( !visited[nx][ny] ) // 且沒走過
                    if( ( nx == 0 || nx == maze.size()-1) || ( ny == 0 || ny == maze[0].size()-1) )
                      return ans;
                    else
                      q.push({nx,ny});
                } // if
            } // for
        } // for
      } // while
      return -1;
    } // bfs

    // bool valid(int x, int y, int n, int m){
    //   return x >= 0 && x < n && y >= 0 && y < m;
    // } // valid
};
