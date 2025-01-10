class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int result = 0;
        // dp[i][j] substring from i to j is pallindrome or not if true then yes and if false then no
        for (int length = 1; length <= n; length++) {
            for (int i = 0; i + length - 1 < n; i++) {
                int j = i + length - 1;
                if (i == j) {
                    dp[i][j] = true;
                } else if (i + 1 == j) {
                    dp[i][j] = (s[i] == s[j]) ? true : false;
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1] == true)
                                   ? true
                                   : false;
                }
                if (dp[i][j])
                result += 1;
            }
           
        }
        return result;
    }
};