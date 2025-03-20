class Solution {
public:
    int mod = 1e9 + 7;
    int dp[31][1001];

    int solve(int num, int k, int target, int sum) {
        if (num == 0) {
            return sum == target ? 1 : 0;
        }

        if (dp[num][sum] != -1) {
            return dp[num][sum];
        }

        int ways = 0;
        for (int i = 1; i <= k; i++) {
            if (sum + i > target)
                break;
            ways = (ways + solve(num - 1, k, target, sum + i)) % mod;
        }

        return dp[num][sum] = ways;
    }

    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(n,k,target,0);
    }
};
