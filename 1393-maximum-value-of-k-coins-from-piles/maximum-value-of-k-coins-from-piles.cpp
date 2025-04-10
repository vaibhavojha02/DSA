#include<bits/stdc++.h>
class Solution {
public:
    int dp[1001][2001];
    int solve(vector<vector<int>>& piles,int idx,int k){
        if(idx==piles.size()){
            return 0;
        }
        if(k<=0)return 0;
        if(dp[idx][k]!=-1){
            return dp[idx][k];
        }
        //not_take
        int not_take = solve(piles,idx+1,k);
        //take 
        int take = 0,sum = 0;
        for(int i = 0;i< min((int)piles[idx].size(),k);i++){
              sum += piles[idx][i];
              take = max(take,sum + solve(piles,idx+1,k-(i+1)));
        }
        return dp[idx][k] =  max(take,not_take);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k)
    {
        memset(dp,-1,sizeof(dp));
        return solve(piles,0,k);
        
    }
};