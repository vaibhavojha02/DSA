class Solution {
public:
    long long appealSum(string s) {
        vector<int> freq(26, 0);
        long long res = 0;
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a'] = i + 1;
            for (int j = 0; j < 26; j++) {
                res += freq[j];
            }
        }
        return res;
    }
};