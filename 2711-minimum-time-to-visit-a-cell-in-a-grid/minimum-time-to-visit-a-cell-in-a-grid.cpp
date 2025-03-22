class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) 
            return -1;  // Impossible case

        vector<vector<int>> minTime(m, vector<int>(n, INT_MAX)); 
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});  
        minTime[0][0] = 0;

        while (!pq.empty()) {
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

          
            if (time > minTime[row][col]) continue;

          
            if (row == m - 1 && col == n - 1) return time;

            for (int i = 0; i < 4; i++) {
                int newRow = row + dx[i];
                int newCol = col + dy[i];

                if (newRow >= 0 && newCol >= 0 && newRow < m && newCol < n) {
                    int arrivalTime;
                    
                    if (grid[newRow][newCol] <= time + 1) {
                        arrivalTime = time + 1; 
                    } else if ((grid[newRow][newCol] - time) % 2 != 0) {
                        arrivalTime = grid[newRow][newCol]; 
                    } else {
                        arrivalTime = grid[newRow][newCol] + 1; 
                    }

                    // Only push if it's an improvement
                    if (arrivalTime < minTime[newRow][newCol])
                    {
                        minTime[newRow][newCol] = arrivalTime;
                        pq.push({arrivalTime, {newRow, newCol}});
                    }
                }
            }
        }
        return -1;
    }
};
