class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long totalProd = 1;
        int zeroCount = 0, idx = -1;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroCount++;
                idx = i;
            } else {
                totalProd = totalProd * nums[i] * 1LL;
            }
        }
        vector<int> ans(n, 0);
        if (zeroCount > 1) {
            return ans;
        }
        if (zeroCount == 1) {
            ans[idx] = totalProd;
            return ans;
        }
        for (int i = 0; i < n; i++) {
            ans[i] = totalProd / (long long)nums[i];
        }
        return ans;
    }
};
