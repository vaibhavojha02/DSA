class Solution {
public:
    int minimumLength(string s) {
       vector<int>mainFreq(26,0);
       for(int i =0;i<s.size();i++){
           mainFreq[s[i]-'a']++;
           if(mainFreq[s[i]-'a']==3){
               mainFreq[s[i]-'a'] -= 2;
           }
       }
       int res = 0;
       for(int i =0;i<26;i++){
           res += mainFreq[i];
       }
       return res;
      
    }
};