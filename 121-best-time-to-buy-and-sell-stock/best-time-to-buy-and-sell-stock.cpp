class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini_cost = prices[0];
        int profit = 0;
        for(int i = 0;i<prices.size();i++){
            profit = max(profit,prices[i]-mini_cost);
            mini_cost = min(mini_cost,prices[i]);
        }
        return profit;
    }
};