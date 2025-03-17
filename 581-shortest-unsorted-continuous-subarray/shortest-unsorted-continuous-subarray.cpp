class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low + 1 < nums.size() && nums[low] <= nums[low + 1])
            low++;
        while (high - 1 >= 0 && nums[high - 1] <= nums[high])
            high--;

        if (low == nums.size() - 1)
            return 0;

        int windowMin = INT_MAX, windowMax = INT_MIN;
        for (int i = low; i <= high; i++)
        {
            windowMin = min(windowMin, nums[i]);
            windowMax = max(windowMax, nums[i]);
        }
        cout<<low<<" "<<high;
        while (low - 1 >= 0 && nums[low - 1] > windowMin)
            low--;
        while (high + 1 <= nums.size() - 1 && nums[high + 1] < windowMax)
            high++;

        return high - low + 1;
    }
};