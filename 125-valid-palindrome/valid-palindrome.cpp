class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(int i =0;i<s.size();i++){
            if(s[i] >= 97 && s[i] <= 122){
               temp.push_back(s[i]);
            }
            else if(s[i] >= 65 && s[i]<=90){
                temp.push_back(tolower(s[i]));
            }
            else if(s[i]>=48 && s[i]<=57){
                temp.push_back(s[i]);
            }
            else{
                continue;
            }
            if(!temp.empty())cout<<temp.back();
        }
        
        int i = 0,j = temp.size()-1;
        while(i<=j){
            if(temp[i]==temp[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }

        return true;
    }
};