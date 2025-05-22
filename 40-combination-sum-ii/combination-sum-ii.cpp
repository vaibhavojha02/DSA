class Solution {
public:
    vector<vector<int>>ans;
    vector<int>ds;
    void solve(vector<int>&candidates, int target, int idx){
        if(idx==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(target >= candidates[idx]){
            ds.push_back(candidates[idx]);
            solve(candidates,target-candidates[idx],idx+1);
            ds.pop_back();
        }
        idx += 1;
        while(idx<candidates.size() && candidates[idx]==candidates[idx-1]){
            idx++;
        }
        solve(candidates,target,idx);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0);
        return ans;
    }
};