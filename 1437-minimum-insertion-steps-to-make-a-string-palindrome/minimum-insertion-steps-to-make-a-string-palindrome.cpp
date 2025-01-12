class Solution {
public:
    int minInsertions(string s) {
        // BOTTOM UP
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i + length - 1 < n; i++) {
                int j = i + length - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};