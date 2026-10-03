class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
        if (a[1] != b[1]) return a[1] < b[1];
          return a[0] < b[0];
      });    
      int prevend = -INT_MAX;
      int count = 0;
      for(int i = 0 ; i < intervals.size() ; i++){
        if(  prevend <= intervals[i][0] ){
          prevend = intervals[i][1];
        } // if
        else
          count++;
      } // for
      return count;
    }
      
};
