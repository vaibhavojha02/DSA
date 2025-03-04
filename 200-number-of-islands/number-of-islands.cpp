class Solution {
public:
    int n,m;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    void dfs(vector<vector<char>>& grid,int row,int col,vector<vector<int>>&vis){
        vis[row][col] = 1;
        for(int i =0;i<4;i++){
            int new_row = row + dx[i];
            int new_col = col + dy[i];
            if(new_row >= 0 && new_row< n && new_col >= 0 && new_col < m && grid[new_row][new_col] == '1' && vis[new_row][new_col]==-1){
                dfs(grid,new_row,new_col,vis);
            }
        }
        return;

    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        int islands =  0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==-1){
                    islands++;
                    dfs(grid,i,j,vis);
                }
            }
        }
        return islands;
    }
};