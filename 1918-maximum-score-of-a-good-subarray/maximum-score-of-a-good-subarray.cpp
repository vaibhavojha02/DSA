class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> next(n);
        vector<int> prev(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (st.empty())
                next[i] = n;
            else
                next[i] = st.top();
            st.push(i);
            cout << next[i];
        }
        cout << endl;
        st = stack<int>();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (st.empty())
                prev[i] = -1;
            else
                prev[i] = st.top();
            st.push(i);
            cout << prev[i];
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            int nextidx = next[i] - 1;
            int previdx = prev[i] + 1;
            if (k <= nextidx && k >= previdx) {
                res = max(res, (nextidx - previdx + 1) * nums[i]);
            }
        }
        return res;
    }
};