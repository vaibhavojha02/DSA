class Solution {
public:
    void next_permutation(string& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
    string getPermutation(int n, int k) {
        vector<string> temp = {"",        "1",        "12",       "123",
                               "1234",    "12345",    "123456",   "1234567",
                               "12345678", "123456789"};
        string nums = temp[n];
        for (int i = 1; i <= k - 1; i++) {
            next_permutation(nums);
        }
        return nums;
    }
};