class Solution {
public:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    int n, m;
    int dfs(int i, int j, vector<vector<int>>& grid, int id) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1) {
            return 0;
        }
        grid[i][j] = id;
        int size = 1;
        for (int k = 0; k < 4; k++) {
            int n_row = i + delRow[k];
            int n_col = j + delCol[k];
            size += dfs(n_row, n_col, grid, id);
        }
        return size;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int id = 2;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(i, j, grid, id);
                    mp[id] = size;
                    id++;
                }
            }
        }
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    set<int> st;
                    for (int k = 0; k < 4; k++) {
                        int n_row = i + delRow[k];
                        int n_col = j + delCol[k];
                        if (n_row >= 0 && n_row < n && n_col >= 0 &&
                            n_col < m) {
                            st.insert(grid[n_row][n_col]);
                        }
                    }
                    int area = 1;
                    for (auto it : st) {
                        area += mp[it];
                    }
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea == 0 ? n * n : maxArea;
    }
};