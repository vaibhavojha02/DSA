class Solution {
    bool isPallindrome(int i, int j, string s) {
        string t = s.substr(i, j - i + 1);
        int start = 0, e = t.size() - 1;
        while (start <= e) {
            if (t[start] == t[e]) {
                start++;
                e--;
            } else {
                return false;
            }
        }
        return true;
    }

public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (isPallindrome(i, j, s)) {
                    count += 1;
                }
            }
        }
        return count;
    }
};