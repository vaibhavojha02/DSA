class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans = 0;
        int start  = 0,end = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int length = 1; length <= n; length++) {
            for (int i = 0; i + length - 1 < n; i++) {
                int j = i + length - 1;
                if(i==j){
                    dp[i][j] = true;
                }
                else if(i+1 == j){
                    dp[i][j] = (s[i]==s[j]);
                }
                else{
                    dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]==true) ? true : false;
                }
                if(dp[i][j]==1 && ans < j-i+1) {
                    start = i;
                    end = j;
                    ans = j-i+1;
                }
            }
        }
        string result = s.substr(start,end-start+1);
        return result;
    }
};