class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        if(n==1)return true;
        for (int i = 1; i < n - 1; i++) {
            if (i+2<n && nums[i] >= nums[i-1] && nums[i + 1] < nums[i] && nums[i + 1] < nums[i - 1] && nums[i+2] <= nums[i])return false;
                
            if (nums[i] < nums[i - 1]) {
                count++;
            }
        }
        if (nums[n - 1] < nums[n - 2])
            count++;
        return (count > 1) ? false : true;
    }
};