class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
      sort(points.begin(),points.end(),[](const auto &a, const auto &b ){
        if (a[1] != b[1]) return a[1] < b[1];
          return a[0] < b[0];
      }); // sort    
      
      int count = 1, prev_end = points[0][1];
      for(int i = 1; i < points.size() ; i++){
        if(prev_end < points[i][0]){
          prev_end = points[i][1];
          count++;
        } // if
      } // for
      return count;
    }
};
