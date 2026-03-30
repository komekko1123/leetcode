class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue <int, vector<int>, greater<int> > pq; // min heap
      // priority_queue<int> pq;
      for( int i = 0; i < nums.size() ; i++){
        if( !pq.empty() && pq.top() < nums[i] && pq.size() == k ){
          pq.pop();
          pq.push(nums[i]);
        } // if

        else if( pq.size() < k )
          pq.push(nums[i]);
      } // for

      return pq.top(); 
    }
};
