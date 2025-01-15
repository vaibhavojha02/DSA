class Solution {
public:
    unordered_map<int, int> dp;
    int binarySearch(vector<vector<int>>& schedule, int endTime) {
        int left = 0, right = schedule.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (schedule[mid][0] >= endTime) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int solve(vector<vector<int>>& schedule, int idx) {
        if (idx >= schedule.size()) {
            return 0;
        }
       
        if (dp.find(idx) != dp.end()) {
            return dp[idx];
        }

        int nextIdx = binarySearch(schedule, schedule[idx][1]);
        int take =
            schedule[idx][2] + solve(schedule, nextIdx);

        int skip = solve(schedule, idx + 1);
        return dp[idx] = max(take, skip);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int n = startTime.size();
        dp.clear();
        vector<vector<int>> schedule(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++) {
            schedule[i][0] = startTime[i];
            schedule[i][1] = endTime[i];
            schedule[i][2] = profit[i];
        }
        sort(schedule.begin(), schedule.end(),
             [&](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
        return solve(schedule, 0);
    }
};