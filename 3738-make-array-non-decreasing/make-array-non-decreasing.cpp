class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int length = 1;
        int mx = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > mx) {
                length++;
                mx = nums[i];
            } else if (nums[i] == mx) {
                length++;
            } else {
                continue;
            }
        }
        return length;
    }
};