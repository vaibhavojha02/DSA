class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q ; // {{row,col},distance}
        for(int i =0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
                else{
                    vis[i][j] =0;
                }
            }
        }
        vector<int>delRow  = {-1,1,0,0};
        vector<int>delCol  = {0,0,-1,1};
        while(!q.empty())
        {
           int row = q.front().first.first;
           int col = q.front().first.second;
           int distance = q.front().second;
           q.pop();
           dist[row][col] = distance;
           for(int i =0;i<4;i++){
              int r = row+ delRow[i];
              int c = col + delCol[i];
              if(r>=0 && r<n && c>=0 && c<m && vis[r][c]!=1)
              {
                vis[r][c] = 1; 
                q.push({{r,c},distance+1});
              }
           }

        }
        return dist;
    }
};