class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(auto i : knowledge){
            mp[i[0]] = i[1];
        }
        string ans = "";
        int i = 0;
        while(i<s.size()){
            if(s[i]=='(')
            {
                int j = i;
                while(s[j]!=')'){
                    j++;
                }
                cout<<j<<" "<<i<<" ";
                string temp = s.substr(i+1,j-i-1);
                if(mp.find(temp)!=mp.end()){
                    ans += mp[temp];
                }
                else{
                    ans +=  "?";
                }
                i = j+1;
            }
            else{
                ans.push_back(s[i]);
                i++;
            }
        }
        return ans;
    }
};