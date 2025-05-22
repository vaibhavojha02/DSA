class Solution {
public:
    vector<vector<int>> ans;
    vector<int> ds;
    void solve(vector<int>& candidates, int target, int idx)
    {

        if (idx == candidates.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }
        if (target >= candidates[idx])
        {
            ds.push_back(candidates[idx]);
            solve(candidates, target - candidates[idx], idx);
            ds.pop_back();
        }
        solve(candidates, target, idx + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, target, 0);
        return ans;
    }
};