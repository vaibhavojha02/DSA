class Solution {
public:
    
    bool isPalindrome(string s) {
        int i = 0,j=s.size()-1;
        while(i<=j){
            while(i<j && (isalnum(s[i])==false))i++;
            while(i<j && (isalnum(s[j])==false))j--;
            cout<<(char)tolower(s[i])<<" "<<(char)tolower(s[j])<<" ";
            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            i++;
            j--;
            
        }
        return true;
    }
};