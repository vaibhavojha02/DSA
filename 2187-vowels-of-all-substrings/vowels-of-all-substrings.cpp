class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    long long countVowels(string word) {
        int n = word.size();
        long long ans = 0LL;
        vector<long long> freq(26, 0LL);
        for (int i = 0; i < n; i++) {
            freq[word[i] - 'a'] += ((i + 1) * 1LL * (n - i));
        }
        for(int i =0;i<26;i++){
           if(isVowel(i+'a')){
             ans += freq[i];
           }
        }

        return ans;
    }
};