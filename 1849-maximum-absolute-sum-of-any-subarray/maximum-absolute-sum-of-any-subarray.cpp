class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minPreSum = INT_MAX, maxPreSum = INT_MIN;
        int prefSum = 0, res = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            prefSum += nums[i];
            minPreSum = min(minPreSum, prefSum);
            maxPreSum = max(maxPreSum, prefSum);
            if (prefSum < 0) {
                res = max({abs(prefSum), res, abs(prefSum - maxPreSum)});
            } else {
                res = max({prefSum, res, prefSum - minPreSum});
            }
        }
        return res;
    }
};