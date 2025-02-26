class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        vector<int>div(n,1);
        if(m==1)return div;
        long long rem = 0;
        for(int i =0;i<n;i++){
            int currDig = word[i] - '0';
            long long newDividend = (rem*10) + currDig;
            if(newDividend%m){
                div[i] = 0;
            }
            rem = newDividend%m;
        }
        return div;
    }
};