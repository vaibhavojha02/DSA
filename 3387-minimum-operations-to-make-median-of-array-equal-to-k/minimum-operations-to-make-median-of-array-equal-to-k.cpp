class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        long long ops = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mid;

        if (n % 2 == 1) {
            mid = n / 2;
        } else {
            mid = (n + 1) / 2;
        }
        cout << mid << endl;
        if (nums[mid] == k)
            return 0;

        for (int i = mid + 1; i < n; i++) {
            if (nums[i] >= k)
                break;
            if (nums[i] < k) {
                ops += abs(k * 1LL - nums[i] * 1LL);
            }
        }

        for (int i = mid - 1; i >= 0; i--) {

            if (nums[i] <= k)
                break;
            if (nums[i] > k) {
                ops += abs(k * 1LL - nums[i] * 1LL);
            }
        }
        ops += abs(k - nums[mid]);
        return ops;
    }
};