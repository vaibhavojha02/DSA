class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> height(n, vector<int>(m, -1)); // Initialize heights as -1
        queue<pair<int, int>> q; // Queue for BFS
        vector<int> delRow = {-1, 0, 1, 0}; // Directions for row
        vector<int> delCol = {0, 1, 0, -1}; // Directions for column

        // Initialize the queue with all water cells
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0; // Water cells have height 0
                    q.push({i, j});  // Add water cells to the queue
                }
            }
        }

        // BFS to calculate heights
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                // If the cell is valid and unvisited
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && height[newRow][newCol] == -1) {
                    height[newRow][newCol] = height[row][col] + 1; // Increment height
                    q.push({newRow, newCol}); // Add the cell to the queue
                }
            }
        }

        return height;
    }
};
