class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a'] = i;
        }
        int left = 0,right = 0;
        vector<int>ans;
        for(int i = 0;i<s.size();i++){
            right = max(right,freq[s[i]-'a']);
            if(i==right){
                int l = right - left + 1;
                ans.push_back(l);
                left = right+1;
            }
        }
        return ans;

    }
};