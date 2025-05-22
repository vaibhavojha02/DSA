class Solution {
public:
    vector<vector<string>> ans;
    vector<string> ds;
    bool isPallindrome(string temp) {
        int s = 0;
        int e = temp.size() - 1;
        while (s <= e) {
            if (temp[s] != temp[e]) {
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
    void solve(string s, int idx) {
        if (idx == s.size()) {
            ans.push_back(ds);
            return;
        }
        for (int i = idx + 1; i <= s.size(); i++) {
            string temp = s.substr(idx, i - idx);
            if (isPallindrome(temp)) {
                ds.push_back(temp);
                solve(s, i);
                ds.pop_back();
            } else {
                continue;
            }
        }
    }
    vector<vector<string>> partition(string s) {
        solve(s, 0);
        return ans;
    }
};