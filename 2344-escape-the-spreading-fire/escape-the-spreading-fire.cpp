class Solution {
public:
    int m, n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool check(vector<vector<int>>& vis, int mid) {
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        int currTime = mid;
        
        if (vis[0][0] != -1 && currTime >= vis[0][0])
            return false;

        q.push({0, 0});
        visited[0][0] = currTime;

        while (!q.empty()) {
            int t = q.size();
            currTime++;
            while (t--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int new_row = row + dx[i];
                    int new_col = col + dy[i];

                    if (new_row < 0 || new_col < 0 || new_row >= m || new_col >= n || 
                        vis[new_row][new_col] == -1 || visited[new_row][new_col] != -1)
                        continue;

                    if (new_row == m - 1 && new_col == n - 1 && currTime <= vis[m - 1][n - 1])
                        return true;

                    if (currTime < vis[new_row][new_col]) {
                        visited[new_row][new_col] = currTime;
                        q.push({new_row, new_col});
                    }
                }
            }
        }
        return false;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, INT_MAX));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 0;
                }
                else if(grid[i][j]==2){
                    vis[i][j] = -1;
                }
            }
        }

        int mini_time = 0;
        while (!q.empty()) {
            int t = q.size();
            while (t--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int new_row = row + dx[i];
                    int new_col = col + dy[i];
                    if (new_row >= 0 && new_col >= 0 && new_row < m && new_col < n &&
                        vis[new_row][new_col] == INT_MAX && grid[new_row][new_col] != 2) {
                        vis[new_row][new_col] = mini_time + 1;
                        q.push({new_row, new_col});
                    }
                }
            }
            mini_time++;
        }

        
        for(int i =0 ;i<m;i++){
            for(int j = 0;j<n;j++){
                cout<<vis[i][j]<<" ";
            }
            cout<<endl;
        }

        int ans = -1;
        int low = 0, high = m * n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(vis, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans == m * n ? 1e9 : ans;
    }
};
