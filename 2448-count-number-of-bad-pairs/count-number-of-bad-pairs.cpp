class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans  =0;
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int j=0;j<n;j++){
            if(mp.find(j-nums[j])!=mp.end()){
                ans += (j-mp[j-nums[j]]);
            }
            else{
                ans += j;
            }
            mp[j-nums[j]]++;
        }
        return ans;
    }
};