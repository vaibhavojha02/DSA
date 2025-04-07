class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end());
        int len = 0;
        string ans = "";
        for (auto str : dictionary)
        {
            int i = 0, j = 0;
            while (i < str.size() && j < s.size())
            {
                if (str[i] == s[j]) {
                    i++;
                    j++;
                } else {
                    j++;
                }
            }
            if (i == str.size() && str.size() > len) {
                ans = str;
                len = str.size();
                continue;
            }
        }
        return ans;
    }
};