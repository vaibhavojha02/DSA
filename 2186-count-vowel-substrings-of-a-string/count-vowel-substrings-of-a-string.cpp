class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int countVowelSubstrings(string word) {
        int n = word.size();
        vector<int> nextIdx(n, -1);
        int prev = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1 && isVowel(word[i]) && isVowel(word[i + 1])) {
                nextIdx[i] = prev;
            } else if (isVowel(word[i])) {
                nextIdx[i] = prev;
                prev = i;
            } else {
                prev = -1;
                nextIdx[i] = prev;
            }
            cout << nextIdx[i] << " ";
        }
        int i = 0, j = 0;
        int other = 0;
        int ans = 0;
        unordered_map<char, int> mp;
        while (j < n) {
            if (isVowel(word[j])) {
                mp[word[j]]++;
            } else {
                other++;
            }
            while (other > 0)
            {
                if (isVowel(word[i])) {
                    mp[word[i]]--;
                    if (mp[word[i]] == 0) {
                        mp.erase(word[i]);
                    }
                } else {
                    other--;
                }
                i++;
            }
            while (mp.size() == 5 && other == 0) {
                int idx = nextIdx[j];
                if (idx == -1) {
                    ans++;
                } else {
                    ans += idx - j + 1;
                }
                mp[word[i]]--;
                if (mp[word[i]] == 0) {
                    mp.erase(word[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};