class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> row;
        unordered_map<int, vector<int>> col;
        for (auto i : buildings) {
            int r = i[0];
            int c = i[1];
            row[r].push_back(c);
            col[c].push_back(r);
        }
        for (auto &i : row) {
            sort(i.second.begin(), i.second.end());
        }
        for (auto &i : col) {
            sort(i.second.begin(), i.second.end());
        }
        int res = 0;
        for (auto i : buildings) {
            int r = i[0];
            int c = i[1];
            bool left = false, right = false, up = false, down = false;
            if (row[r].back() > c && row[r].front() < c) {
                left  = true;
                right = true;
            }
            if (col[c].back() > r && col[c].front() < r) {
                up    = true;
                down  = true;
            }
            if (left && right && up && down) {
                res++;
            }
        }
        return res;
    }
};