class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // Track the last seen positions of minK and maxK
        int minIdx = -1, maxIdx = -1;

        // Track the last position where an invalid number (outside [minK,
        // maxK]) was seen
        int start = -1;

        // Final answer to store the total number of valid subarrays
        long long res = 0;

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {

            // If the current number is invalid (outside [minK, maxK]), reset
            // everything
            if (nums[i] < minK || nums[i] > maxK) {
                minIdx = -1;
                maxIdx = -1;
                start = i; // New potential start for future valid subarrays
            }

            // Update last seen index of minK
            if (nums[i] == minK) {
                minIdx = i;
            }

            // Update last seen index of maxK
            if (nums[i] == maxK) {
                maxIdx = i;
            }

            // If both minK and maxK have been seen in the current valid window
            if (maxIdx != -1 && minIdx != -1) {
                // Count of valid subarrays ending at current index:
                // starts from just after the last invalid index (start + 1) up
                // to min(minIdx, maxIdx)
                res += min(minIdx, maxIdx) - start;
            }
        }

        return res;
    }
};