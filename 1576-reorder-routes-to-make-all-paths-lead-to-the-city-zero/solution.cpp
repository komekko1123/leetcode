class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
      int ans = 0;
      vector<bool> visited(n,false);
      vector<vector<pair<int,int>>> graph(n);
      for( auto &c : connections ){
        int a = c[0];
        int b = c[1];
        graph[a].push_back({b,1});
        graph[b].push_back({a,0});
      } // for

      ans = dfs(0,graph,visited);
      return ans;
    }

    int dfs( int index, vector<vector<pair<int,int>>> &graph, vector<bool> &visited ) {
      visited[index] = true;
      int ans = 0;
      for(int i = 0 ; i < graph[index].size() ; i++){
        if(  visited[graph[index][i].first] == false)
          ans += dfs(graph[index][i].first,graph,visited) + graph[index][i].second;
      } // for  
      return ans;
    } // dfs
};
