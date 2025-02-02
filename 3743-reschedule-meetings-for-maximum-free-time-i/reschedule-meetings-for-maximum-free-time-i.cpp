class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size();

        vector<int> freeTimes;
        freeTimes.push_back(startTime[0]);
        for (int i = 1; i < n; i++) {
            freeTimes.push_back(startTime[i] - endTime[i - 1]);
        }
        freeTimes.push_back(eventTime - endTime[n - 1]);
        int n1 = freeTimes.size();
        int i = 0, j = 0;
        long long sum = 0;
        k = k + 1;
        long long ans = 0;
        while (j < n1) {
            sum += freeTimes[j];
            if (j - i + 1 < k) {
                j++;
            } else {
                ans = max(ans, sum);
                sum -= freeTimes[i];
                i++;
                j++;
            }
        }
        return (int)ans;
    }
};