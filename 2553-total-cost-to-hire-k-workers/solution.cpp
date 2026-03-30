class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
      if(costs.size() == 1)
        return costs[0];
      priority_queue<int, vector<int>, greater<int>> pq1;  
      priority_queue<int, vector<int>, greater<int>> pq2;
      long long ans = 0;
        int l = 0;
        int r = costs.size() - 1;
        for (int i = 0; i < candidates && l <= r; i++) {
            pq1.push(costs[l++]);
        }
        for (int i = 0; i < candidates && l <= r; i++) {
            pq2.push(costs[r--]);
        }

        while (k--) {
            if (pq2.empty() || (!pq1.empty() && pq1.top() <= pq2.top())) {
                ans += pq1.top();
                pq1.pop();

                if (l <= r) {
                    pq1.push(costs[l++]);
                } // if
            } // if
            else {
                ans += pq2.top();
                pq2.pop();

                if (l <= r) {
                    pq2.push(costs[r--]);
                } // if
            } // else
        } // while

        return ans; 
    }
};
