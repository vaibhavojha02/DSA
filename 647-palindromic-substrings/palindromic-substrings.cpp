class Solution {
    int dp[1001][1001];
    bool isPallindrome(int i, int j, string s) {
       if(i>j){
         return true;
       }
       if(dp[i][j]!=-1){
        return dp[i][j];
       }
       if(s[i]==s[j]){
         return dp[i][j] =  isPallindrome(i+1,j-1,s);
       }
       return dp[i][j] = false;
    }

public:
    int countSubstrings(string s) {
        memset(dp,-1,sizeof(dp));
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (isPallindrome(i, j, s)) {
                    count += 1;
                }
            }
        }
        return count;
    }
};