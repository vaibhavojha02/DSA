class Solution {
public:
    bool solve(vector<int>& chargeTimes, vector<int>& runningCosts,
               long long budget, int mid) {
        long long cost = 0;
        int i = 0, j = 0;
        deque<int> dq;
        long long sum = 0;

        while (j < chargeTimes.size()) {
            sum += runningCosts[j];

            while (!dq.empty() && chargeTimes[dq.back()] < chargeTimes[j]) {
                dq.pop_back();
            }
            dq.push_back(j);

            if (j - i + 1 < mid) {
                j++;
            } else {

                cost = chargeTimes[dq.front()] + mid * 1LL * sum;
                if (cost <= budget)
                    return true;

                sum -= runningCosts[i];
                if (dq.front() == i)
                    dq.pop_front(); // Also clean if it’s exactly i
                i++;
                j++;
            }
        }
        return false;
    }

    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts,
                      long long budget) {
        long long low = 1, high = chargeTimes.size();
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (solve(chargeTimes, runningCosts, budget, mid)) {
                ans = max(ans, mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
