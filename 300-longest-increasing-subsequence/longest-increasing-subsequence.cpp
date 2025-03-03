class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            cout<<dp[i]<<" ";
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};