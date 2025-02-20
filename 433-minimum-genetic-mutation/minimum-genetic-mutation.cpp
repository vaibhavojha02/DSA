class Solution {
public:
    vector<char> arr = {'A', 'C', 'G', 'T'};
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        unordered_set<string> visited;
        visited.insert(start);
        queue<pair<string, int>> q;
        q.push({start, 0});
        int ans = INT_MAX;
        int level = 0;
        while (!q.empty()) {

            string temp = q.front().first;
            int currlevel = q.front().second;
            q.pop();
            if (temp == end)
            {
                ans = min(currlevel, ans);
            }

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 8; j++) {
                    string neigbour = temp;
                    if (neigbour[j] != arr[i]) {

                        neigbour[j] = arr[i];
                        if (visited.find(neigbour) == visited.end() &&
                            st.find(neigbour) != st.end()) {
                            q.push({neigbour, currlevel + 1});
                            visited.insert(neigbour);
                        }
                    }
                }
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};