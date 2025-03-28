class Solution {
public:
    int m, n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool check(vector<vector<int>>& vis, int mid) {
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        int currTime = mid;
        if (vis[0][0] <= mid)
            return false;
        q.push({0, 0});
        visited[0][0] = 1;
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
                    if (new_row >= 0 && new_col >= 0 && new_col < n &&
                        new_row < m && visited[new_row][new_col] == -1 &&
                        vis[new_row][new_col] != -1) {
                        if (new_row == m - 1 && new_col == n - 1 &&
                            currTime <= vis[new_row][new_col])
                            return true;

                        if (vis[new_row][new_col] <= currTime)
                            continue;
                        else {

                            visited[new_row][new_col] = 1;
                            q.push({new_row, new_col});
                        }
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
                } else if(grid[i][j]==2) {
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
                    if (new_row >= 0 && new_col >= 0 && new_row < m &&
                        new_col < n && vis[new_row][new_col] == INT_MAX){
                        vis[new_row][new_col] = mini_time + 1;
                        q.push({new_row, new_col});
                    }
                }
            }
            mini_time++;
        }
        // now we are having minimum time requiref for fore to reacch cell 0,0;
        // now in this time range we can only start because after that there
        // will be fire in cell 0,0
        int ans = -1;
        int low = 0, high = m * n + 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(vis, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans == m * n + 1 ? 1e9 : ans;
    }
};