class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i = 2; i <= numRows; i++) {
            vector<int> temp2 = ans.back();
            vector<int> temp1;
            for (int i = 0; i <= temp2.size(); i++) {
                if (i == 0 || i == temp2.size()) {
                    temp1.push_back(1);
                } else {
                    temp1.push_back(temp2[i] + temp2[i - 1]);
                }
            }
            ans.push_back(temp1);
        }
        return ans;
    }
};