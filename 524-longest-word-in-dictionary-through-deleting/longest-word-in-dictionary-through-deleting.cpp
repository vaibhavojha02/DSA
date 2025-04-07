class Solution {
public:
    string findLongestWord(string s, vector<string>& words) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]].push_back(i);
        }
        sort(words.begin(), words.end());
        int len = 0;
        string ans = "";
        for (auto st : words) {
            int maxi = -1;
            for (int i = 0; i < st.size(); i++) {
                int idx =
                    upper_bound(mp[st[i]].begin(), mp[st[i]].end(), maxi) -
                    mp[st[i]].begin();

                if (idx == mp[st[i]].size())
                    break;
                else {
                    maxi = mp[st[i]][idx];
                }
                if (i == st.size() - 1 && len < st.size()) {
                    ans = st;
                    len = st.size();
                }
            }
        }
        return ans;
    }
};