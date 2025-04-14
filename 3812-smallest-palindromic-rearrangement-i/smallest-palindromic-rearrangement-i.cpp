class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int idx = n/2;
        sort(s.begin(),s.begin()+idx);
        cout<<s<<endl;
        if(n%2==0){
            sort(s.begin()+idx,s.end());
            reverse(s.begin()+idx,s.end());
            cout<<s;
        }
        else{
            sort(s.begin()+idx+1,s.end());
            reverse(s.begin()+idx+1,s.end());
            cout<<s<<endl;
        }
        return s;
    }
};