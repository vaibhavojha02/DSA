class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start <= end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k % n == 0) {
            return;
        } else {
            k = k % n;
            if (n - k + 1 >= 0)
            reverse(nums, n - k , n-1);
            reverse(nums, 0, n - k-1);
            reverse(nums, 0, n-1);
        }
    }
};