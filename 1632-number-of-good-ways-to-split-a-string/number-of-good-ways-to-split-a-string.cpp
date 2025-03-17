class Solution {
public:
    int numSplits(string s) {
        vector<int> freq1(26, 0);
        for (int i = 0; i < s.size(); i++) {
            freq1[s[i] - 'a']++;
        }
        int res = 0;
        vector<int> freq2(26, 0);
        for (int i = 0; i < s.size(); i++) {
            freq2[s[i] - 'a']++;
            int count1 = 0, count2 = 0;
            for (int j = 0; j < 26; j++) {
                if (freq2[j] > 0)
                    count1++;
            }
            for (int j = 0; j < 26; j++){
                if (freq1[j] - freq2[j] > 0) {
                    count2++;
                }
            }
            if (count1 == count2)
                res++;
        }

        return res;
    }
};