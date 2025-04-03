class Solution {
public:
    vector<int>dp;
    int solve(int n) {
        if (floor(sqrt(n))==ceil(sqrt(n)))return 1;
        if(dp[n]!=-1)return dp[n];
        int mini = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            int square = i*i;
            mini = min(mini,1 + solve(n-square));
        }
        return dp[n] =  mini;
    }
    int numSquares(int n) {
        if (floor(sqrt(n))==ceil(sqrt(n)))return 1;
        dp.resize(n+1,-1);
        cout<<"HI"<<endl;
        return solve(n);
    }
};