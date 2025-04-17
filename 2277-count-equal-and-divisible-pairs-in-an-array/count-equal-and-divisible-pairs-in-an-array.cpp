class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int pairs = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j] && ((i * j) % k == 0)){
                    pairs++;
                }
            }
        }
        return pairs;
    }
};