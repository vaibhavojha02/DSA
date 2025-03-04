class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pq.push({grid[i][j], i});
            }
        }
        int selected = 0;
        long long sum = 0 ;
        if(k==0)return 0;
        
        while (!pq.empty()) {
            int ele = pq.top().first;
            if (limits[pq.top().second] > 0)
            {
                limits[pq.top().second] -= 1;
                sum += ele;
                selected++;
            }
            if (selected == k)
                break;
            pq.pop();
        }
        return sum;
    }
};