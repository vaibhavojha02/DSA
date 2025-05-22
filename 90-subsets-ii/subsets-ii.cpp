class Solution {
public:
    vector<vector<int>>ans;
    vector<int>ds;
    void solve(int idx,vector<int>&nums){
        if(idx==nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]);
        solve(idx+1,nums);
        ds.pop_back();
        idx += 1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]){
            idx++;
        }
        solve(idx,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(0,nums);
        return ans;
        

    }
};