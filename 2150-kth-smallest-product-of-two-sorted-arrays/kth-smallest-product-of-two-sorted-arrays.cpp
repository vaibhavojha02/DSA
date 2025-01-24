class Solution {
public:
    bool check(long long mid, vector<int>& nums1, vector<int>& nums2,
               long long k) {
        long long cnt = 0;
        int n2 = nums2.size();
         for (auto &num : nums1) {
                if (num == 0) {
                    if (mid >= 0) cnt += n2;
                }
                else if (num > 0) {
                    double target = (double)mid / num;
                    int j = upper_bound(begin(nums2), end(nums2), target) - begin(nums2);
                    cnt += j;
                }
                else {
                    double target = (double)mid / num;
                    int j = lower_bound(begin(nums2), end(nums2), target) - begin(nums2);
                    cnt += (n2 - j);
                }
        }
        return cnt >= k;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        int n = nums1.size(), m = nums2.size();
        if (n > m) {
            return kthSmallestProduct(nums2, nums1, k);
        }

        long long low = -1e10, high = 1e10;

        long long ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid, nums1, nums2, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};