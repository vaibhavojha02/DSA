class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        sort(packages.begin(),packages.end());
        long long ans = LONG_MAX, mod = 1e9+7,packageSum = 0;
        for(int a : packages){
            packageSum += a;
        }
        for(auto&box : boxes){
            sort(box.begin(),box.end());
            if(box[box.size()-1]<packages[packages.size()-1])continue;
            long long curr = 0,i=0,j;
            for(int b : box){
                j = upper_bound(packages.begin()+i,packages.end(),b)-packages.begin();
                curr += (b*(j-i));
                i=j;
            }
            ans = min(ans,curr);
        }
        return ans<LONG_MAX ? (ans-packageSum)%mod : -1;
    }
};