class Solution {
public:
    int n, m;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(vector<vector<int>>& grid, int row, int col,
             vector<vector<int>>& vis,int& count) {
        vis[row][col] = 1;
        count++;
        for (int i = 0; i < 4; i++) {
            int new_row = row + dx[i];
            int new_col = col + dy[i];
            if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m &&
                grid[new_row][new_col] == 1 && vis[new_row][new_col] == -1) {
                dfs(grid, new_row, new_col, vis,count);
            }
        }
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        int max_area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == -1) {
                    int count = 0;
                    dfs(grid,i,j,vis,count);
                    max_area = max(max_area,count);
                }
            }
        }
        return max_area;
    }
};