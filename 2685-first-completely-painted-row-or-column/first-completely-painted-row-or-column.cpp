class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> mp;
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[mat[i][j]] = {i, j};
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            if (mp.find(arr[i]) != mp.end()) {
                pair<int, int> c = mp[arr[i]];
                rowCount[c.first]++;
                colCount[c.second]++;
                if (rowCount[c.first] == n || colCount[c.second] == m ){
                    return i;
                }
            }
        }
        return -1;
    }
};