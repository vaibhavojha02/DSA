class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int j = 0;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == 0) {
                int j = i;
                while (j<nums.size() && nums[j] == 0) {
                    ans += (j - i + 1);
                    j++;
                }
                i = j;
            } else {
                i++;
            }
        }
        return ans;
    }
};