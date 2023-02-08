class Solution {
public:
    int jump(vector<int>& nums) {
      int i = 0, ans = 0;
      int n = nums.size();
      int j = n - 1;
      vector<int> answer;
      while( j != 0 ){
        for( i = 0 ; i < j ; i++){
          if( i + nums[i] >= j ) 
            break;        
        } // for
        answer.push_back(i);
        j = i;
      } // 
      
      if ( n-1 > 0 )
        return answer.size();
      else 
        return 0;
    } // for


};
