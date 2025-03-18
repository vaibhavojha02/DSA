class Solution {
public:
    int longestNiceSubarray(vector<int>& nums)
    {
        int ans = 0;
        if(nums.size() < 1) return 0;
        int i = 0, j = 0,mask = 0; 
        while(j < nums.size()) {
            while(i<j && (mask&nums[j])!=0){
                mask ^= nums[i];
                i++;
            }
            mask |= nums[j];
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
