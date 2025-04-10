class Solution {
public:
    int m, n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool isValid(int row, int col, vector<vector<int>>& vis,
                 vector<vector<int>>& grid) {
        return row >= m || row < 0 || col < 0 || col >= n ||
               vis[row][col] != -1 || grid[row][col] == 0;
    }
    void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<int>>& grid, queue<pair<int,int>>& q) {
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int newrow = row + dx[i];
            int newcol = col + dy[i];
            if (!isValid(newrow, newcol, vis, grid)) {
                q.push({newrow, newcol});
                dfs(newrow, newcol, vis, grid, q);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, -1));
        queue<pair<int, int>> q; //{row,col};
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j] == -1) {
                    q.push({i, j});
                    dfs(i, j, vis, grid, q);
                    int dist = 0;
                    while (!q.empty()) {
                        int t = q.size();
                        while (t--)
                        {
                            int row = q.front().first;
                            int col = q.front().second;
                            q.pop();
                            for (int i = 0; i < 4; i++)
                            {
                                int newrow = row + dx[i];
                                int newcol = col + dy[i];
                                if (newrow >= 0 && newrow < m && newcol >= 0 &&
                                    newcol < n && vis[newrow][newcol] == -1){
                                    if(grid[newrow][newcol]==0){
                                      vis[newrow][newcol] = 1;
                                      q.push({newrow, newcol});
                                    }
                                    else{
                                        return dist;
                                    }
                                   
                                }
                            }
                        }
                        dist++;
                    }
                }
            }
        }
        return -1;
    }
};