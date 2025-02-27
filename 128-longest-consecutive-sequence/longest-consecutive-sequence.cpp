class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        int maxRes = 0;
        for (auto i : mp) {
            if (mp.find(i.first - 1) == mp.end()) {
                int count = 0;
                int start = i.first;
                while (mp.find(start) != mp.end()) {
                    start += 1;
                    count++;
                }
                maxRes = max(maxRes, count);
            }
        }
        return maxRes;
    }
};
