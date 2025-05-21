class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        map<int, int> mp;
        for (int i = 0; i < intervals.size(); i++) {
            mp[intervals[i][0]]++;
            mp[intervals[i][1]]--;
        }
        auto it = mp.begin();
        int firstt = it->first;
        int sum = 0;
        for (auto& i : mp) {
            if (firstt == -1) {
                firstt = i.first;
            }
            sum += i.second;
            if (sum == 0) {
                ans.push_back({firstt, i.first});
                firstt = -1;
            }
        }
       return ans;
    }
};