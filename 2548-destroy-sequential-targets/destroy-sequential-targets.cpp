class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, int> mp;
        int maxfreq = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int mod = nums[i] % space;
            mp[mod]++;
            if (mp[mod] > maxfreq)
            {
                maxfreq = mp[mod];
            }
        }
        int res = INT_MAX;
        for (auto i : nums) {
            if (mp[i%space] == maxfreq) {
                res = min(res, i);
            }
        }
        return res;
    }
};