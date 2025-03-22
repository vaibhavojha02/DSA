class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int m, n;
    int dp[51][51][101];
    bool solve(vector<vector<int>>& vis, vector<vector<int>>& grid, int row,
               int col, int health) {

        

        if (row == m - 1 && col == n - 1) {
            return (grid[row][col] == 1) ? (health >= 1) : (health > 0);
        }
        if (health <= 0)
            return false; 
        
        if(dp[row][col][health]!=-1){
            return dp[row][col][health];
        }
        vis[row][col] = 1; // Mark visited

        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if (newRow >= 0 && newCol >= 0 && newRow < m && newCol < n &&
                vis[newRow][newCol] == -1) {

                int newHealth =
                    (grid[newRow][newCol] == 1) ? health - 1 : health;

                if (solve(vis, grid, newRow, newCol, newHealth)) {
                    return true;
                }
            }
        }

        vis[row][col] = -1; // Unmark before backtracking
        return  dp[row][col][health] =  false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m = grid.size(), n = grid[0].size();
        if (grid[0][0] == 1) {
            if (health < 2)
                return false; // You cannot survive on (0,0)
            health--;         // Deduct health for standing on (0,0)
        }
        memset(dp,-1,sizeof(dp));
        vector<vector<int>> vis(m, vector<int>(n, -1));
        return solve(vis, grid, 0, 0, health);
    }
};
