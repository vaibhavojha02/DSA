class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        stack<int> st;
        vector<int> next(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        for (auto i : next) {
            cout << i << " ";
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int nextG = next[i];
            int idx =
                lower_bound(mp[nums[i]].begin(), mp[nums[i]].end(), nextG) -
                mp[nums[i]].begin();
            int j = lower_bound(mp[nums[i]].begin(), mp[nums[i]].end(), i) -
                    mp[nums[i]].begin();

            ans += (idx - j);
        }
        return ans;
    }
};