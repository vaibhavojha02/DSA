class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>temp;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    temp.push_back({i,j});
                }
            }
        }
        for(int i = 0;i<temp.size();i++){
            int row = temp[i].first;
            int col = temp[i].second;
            for(int j=0;j<m;j++){
                matrix[row][j] = 0;
            }
            for(int j = 0 ;j<n;j++){
                matrix[j][col] = 0;
            }
        }
        return ;
        
    }
};