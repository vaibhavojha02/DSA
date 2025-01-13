class Solution {
public:
    int dp[101][101][101];
    int solve(vector<int>& nums, int idx, int ops1, int ops2, int k) {
        if (idx >= nums.size()) {
            return 0;
        }
        if(dp[idx][ops1][ops2]!=-1){
            return dp[idx][ops1][ops2];
        }
        int thirdOp = 1e9;
        int firstOp = 1e9, secondOp = 1e9, fourthOp = 1e9, fifthOp = 1e9;
        //first op
        if (ops1 > 0) {
            int ceilVal = (nums[idx] + 1) / 2; // Ceiling operation
            firstOp = ceilVal + solve(nums, idx + 1, ops1 - 1, ops2, k);
        }
        //second op
        if (ops2 > 0 && nums[idx] >= k) {
            secondOp = (nums[idx] - k) + solve(nums, idx + 1, ops1, ops2 - 1, k);
        }
        //first and second combined on index
        if(ops1 > 0 && ops2 > 0) {
            int newVal = (nums[idx] + 1) / 2;
            if(newVal - k >= 0) {
                fifthOp = (newVal - k) + solve(nums, idx + 1, ops1 - 1, ops2 - 1, k);
            }
            if(nums[idx] >= k) {
                newVal = nums[idx] - k;
                newVal = (newVal + 1) / 2;
                fourthOp = newVal + solve(nums, idx + 1, ops1 - 1, ops2 - 1, k);
            }
        }
        
        thirdOp = nums[idx] + solve(nums, idx + 1, ops1, ops2, k);
        
        return dp[idx][ops1][ops2] = min({firstOp, secondOp, thirdOp, fourthOp, fifthOp});
    }
    
    int minArraySum(vector<int>& nums, int k, int ops1, int ops2) {
        memset(dp,-1,sizeof(dp));
        return solve(nums, 0, ops1, ops2, k);
    }
};