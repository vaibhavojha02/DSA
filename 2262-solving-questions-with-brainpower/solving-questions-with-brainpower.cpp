class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);  // One extra space to handle base case easily
        
        for (int i = n - 1; i >= 0; i--) {
            int points = questions[i][0];
            int jump = questions[i][1];
            // Choose the max between taking the question and skipping it
            dp[i] = max(dp[i + 1], points + (i + 1 + jump < n ? dp[i + 1 + jump] : 0));
        }
        
        return dp[0];  // Result is the maximum points starting from the first question
    }
};
