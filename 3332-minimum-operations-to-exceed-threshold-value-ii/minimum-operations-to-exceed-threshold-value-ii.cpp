class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(static_cast<long long>(nums[i]));
        }

        int count = 0;

        while (pq.top() < k && pq.size() != 0) {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            long long val = min(x, y) * 2 + max(x, y);
            pq.push(val);
            count++;

            if (pq.top() >= k) {
                return count;
            }
        }

        return count;
    }
};