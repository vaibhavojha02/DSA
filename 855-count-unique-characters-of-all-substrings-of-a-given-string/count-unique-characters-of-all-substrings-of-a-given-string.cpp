class Solution {
public:
    
        int uniqueLetterString(string s) {
            int n = s.size();
            map<char, int> left;
            map<char, vector<int>> right;
            for (int i = n - 1; i >= 0; i--) {
                right[s[i]].push_back(i);
            }
            int ans = 0;
            for (int i = 0; i < n; i++) {
                right[s[i]].pop_back();

                int l = ((left.find(s[i]) != left.end()) ? left[s[i]] : -1);
                int r = ((right[s[i]].size() > 0) ? right[s[i]].back() : n);
                int llen = max(1, i - l);
                int rlen = max(1, r - i);
                int len = rlen * llen;
                ans += len;
                left[s[i]] = i;
            }
            return ans;
        }
    
};