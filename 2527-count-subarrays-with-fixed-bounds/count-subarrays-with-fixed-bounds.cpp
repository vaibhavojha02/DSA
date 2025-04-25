class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minIdx = -1, maxIdx = -1, start = -1;
        long long res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                minIdx = -1;
                maxIdx = -1;
                start = i;
            }
            if (nums[i] == minK) {
                minIdx = i;
            }
            if (nums[i] == maxK) {
                maxIdx = i;
            }
            if (maxIdx != -1 && minIdx != -1) {
                res += min(minIdx, maxIdx) - start;
            }
        }
        return res;
    }
};