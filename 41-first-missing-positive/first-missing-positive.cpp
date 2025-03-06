class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int prev = 1;
        int cnt = 0;
        set<int>st(nums.begin(),nums.end());
        for(auto i : st){
            if(i==0)continue;
            if(i<0)continue;
            if(i==prev){
                cnt++;
                prev = i + 1;
            }
            else{
                break;
            }
        }
        if(cnt==st.size()){
            auto it = st.rbegin();
            return *it + 1;
        }
        return prev==0 ? 1: prev;
    }
};