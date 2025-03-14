class Solution {
public:
    long long check(vector<int>& candies , long long k,int mid){
        long long count = 0;
        for(int i = 0;i<candies.size();i++){
            count += (candies[i]/mid);
        }
        return count;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1, high = INT_MIN;
        for (int i = 0; i < candies.size(); i++) {
            low = min(low, candies[i]);
            high = max(high, candies[i]);
        }
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(candies,k, mid) >= k) {
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};