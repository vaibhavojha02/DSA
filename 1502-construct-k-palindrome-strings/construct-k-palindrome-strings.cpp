class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k)return false;
        vector<int>freq(26,0);
        for(int i =0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        int oddCount = 0;
        for(int i=0;i<26;i++){
            if(freq[i]%2!=0)oddCount++;
        }
        return oddCount > k ? false : true;
    }
};