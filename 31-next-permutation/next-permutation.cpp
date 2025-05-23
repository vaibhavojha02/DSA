class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        // dip
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        // swap
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        // flip
        reverse(nums.begin() + i + 1, nums.end());
    }
};