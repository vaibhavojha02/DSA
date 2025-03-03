class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string, int> mp;
        for (int i = 0; i < dictionary.size(); i++) {

            mp[dictionary[i]]++;
        }
        string ans = "";
        int i = 0;
        while (i < sentence.size()) {
            if (sentence[i] != ' ') {
                int j = i;
                int count = 1;
                bool flag = false;
                string temp = "";
                while (sentence[j] != ' ' && j < sentence.size()) {
                    if (flag == true) {
                        j++;
                        continue;
                    }

                    temp = sentence.substr(i, count);
                    if (mp.find(temp) != mp.end()) {
                        temp += ' ';
                        ans += temp;

                        flag = true;
                    }

                    j++;
                    count++;
                }
                i = j + 1;
                if (flag == false) {
                    temp += ' ';
                    ans += temp;
                }
            }

            else {
                i++;
            }
        }
        ans.pop_back();
        return ans;
    }
};