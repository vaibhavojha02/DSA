class Solution {
public:
    int solve(int start, int end, string& word, int k) {
        int result = 0;

        for (int chars = 1; chars <= 26 && chars*k <= end - start + 1; chars++) {
            vector<int> count(26, 0);
            int goodChars = 0;

            int i = start;

            int windowLength = chars * k;

            for (int j = start; j <= end; j++) {
                char ch = word[j];

                count[ch - 'a']++;
                if (count[ch - 'a'] == k)
                {
                     goodChars++;
                }
                else if (count[ch - 'a'] == k + 1) {
                    goodChars--;
                }

                if (j - i + 1 > windowLength) { // Shrink the window
                    if (count[word[i] - 'a'] == k) {
                        goodChars--;
                    } else if (count[word[i] - 'a'] == k + 1) {
                        goodChars++;
                    }
                    count[word[i] - 'a']--;
                    i++;
                }

                if (goodChars == chars)
                {
                    result++;
                }
            }
        }

        return result;
    }

    int countCompleteSubstrings(string word, int k) {
        int n = word.length();
        int result = 0;
        int last = 0;

        for (int i = 1; i <= n; i++) {
            if (i == n ||
                abs(word[i] - word[i - 1]) > 2) { // Check for big jumps
                result += solve(last, i - 1, word,
                                k); // Count valid substrings in this chunk
                last = i;
            }
        }

        return result;
    }
};