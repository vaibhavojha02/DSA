class Solution {
public:
    int comb(int freq){
        return (freq*(freq-1))/2;
    }
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int prod = nums[i]*nums[j];
                mp[prod]++;
            }
        }
        int ans = 0;
        for(auto it : mp){
            if(it.second>1){
               int Freq = comb(it.second);
               ans += (Freq*8);
            }
        }
        return ans;
    }
};