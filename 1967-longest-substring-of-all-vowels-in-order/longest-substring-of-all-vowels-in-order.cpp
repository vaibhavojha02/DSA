class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();
        int i = 0, j = 0, ans = 0, uniqueVowels = 0;
        
        while (j < n) {
            if (j > 0 && word[j] < word[j - 1]) {
                // Reset if the order breaks
                i = j;
                uniqueVowels = 0;
            }
            
            // Count unique vowels in increasing order
            if (j == i || word[j] != word[j - 1]) uniqueVowels++;

            // If all vowels are present in order, update answer
            if (uniqueVowels == 5) {
                ans = max(ans, j - i + 1);
            }

            j++;
        }
        
        return ans;
    }
};
