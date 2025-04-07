class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int totSum = accumulate(nums.begin(), nums.end(), 0);
        int s1 = 0, s2 = 0;
        int ans1 = INT_MIN, ans2 = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            s1 += nums[i];
            ans1 = max(ans1,s1);
            if(s1<0)s1 = 0;
        }
        for (int i = 0; i < nums.size(); i++) {
            s2 += nums[i];
            ans2 = min(ans2, s2);
            if (s2 > 0)
                s2 = 0;
        }
        return ans1 > 0 ? max(ans1, totSum - ans2) : ans1;
    }
};