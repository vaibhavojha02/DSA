class Solution {
public:
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, pair<int, int>>> q; // {distace,{row,col}};
        int n = maze.size(), m = maze[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        vis[entrance[0]][entrance[1]] = 1;
        set<pair<int,int>>st;
        st.insert({entrance[0],entrance[1]});
        q.push({0, {entrance[0], entrance[1]}});
        int ans = INT_MAX;
        while (!q.empty()) {
            int currdistance = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            if (row == 0 || row == n - 1 || col == 0 || col == m - 1) {
                if(st.find({row,col})==st.end()){
                    ans = min(ans,currdistance);
                }
            }
            for (int i = 0; i < 4; i++) {
                int r = row + dy[i];
                int c = col + dx[i];
                if (r >= 0 && r < n && c >= 0 && c < m && vis[r][c] == -1 &&
                    maze[r][c] == '.') {
                    vis[r][c] = 1;
                    q.push({currdistance + 1, {r, c}});
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};