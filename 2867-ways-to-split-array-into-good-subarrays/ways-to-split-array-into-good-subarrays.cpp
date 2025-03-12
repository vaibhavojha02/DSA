class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int M = 1e9 + 7, n = nums.size();
        long long ans = 1;
        vector<long long> ones;
        // we store all the indices `i` where nums[i] is 1
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                ones.push_back(i);
        }
        // if there is no ones, then the answer is obviously zero
        if (ones.size() == 0)
            return 0;
        // for each gap, calculate the numbers of ways (ones[i] - ones[i - 1])
        // and multiply the answer
        // and take the mod
        for (int i = 1; i < ones.size(); i++) {
            (ans *= (ones[i] - ones[i - 1])) %= M;
        }
        return ans;
    }
};