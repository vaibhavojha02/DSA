class Solution {
public:
    bool check(vector<int>& nums, int x, int k) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
             int j = upper_bound(nums.begin() + i + 1, nums.end(), nums[i] + x) - nums.begin();
            cnt += (j - i - 1); // Add t
        }
        return cnt >= k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[n - 1] - nums[0];

        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(nums, mid, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};