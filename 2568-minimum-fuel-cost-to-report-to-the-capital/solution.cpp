class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
      vector<vector<int>> tree(roads.size()+1);
      int i = 0;
      long long ans = 0 ;
      for( i = 0 ; i < roads.size() ; i++ ){
        tree[roads[i][0]].push_back(roads[i][1]);
        tree[roads[i][1]].push_back(roads[i][0]);
      } // for 
      
      unordered_set<int> s,s2;
      queue<int> q;
      vector<int> rp(roads.size()+1,1);
      vector<int> dist(roads.size()+1,1);
      vector<vector<int>> degree(roads.size()+1);
      q.push(0); 
      while ( !q.empty() ){ // calculate dist of zero
        int node = q.front();
        s2.insert(node);
        q.pop();
        for( auto &tn: tree[node]  ){
          if( s2.count(tn) == 1)
            continue;
          dist[tn] += dist[node]; 
          if ( s2.count(tn) == 0 ){
            s2.insert(tn);
            q.push(tn);
          } // if
        } // for  
      } // while
      
      for( i = 0 ; i < dist.size() ; i++ )
        degree[dist[i] - 1].push_back(i);
      

      for( i = dist.size() - 1 ; i > 0  ; i-- ){
        for( auto &de: degree[i]){ // 7
          for( auto &tn: tree[de]){ // 接7的節點
            if( s.count(tn) == 0 ){
              rp[tn] += rp[de];
              s.insert(de);
            } // if
            else if(  s.count(tn) == 1 )
              continue;
          } // for
          ans += ceil((rp[de] * 1.0) / seats);
        } // for
      } // for
        
      return ans;
    }
};
