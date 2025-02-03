class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 0;
        int incr = 0,decr=0;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                incr++;
                decr++;
                ans = max({ans,incr,decr});
                continue;
            }
            if(nums[i]>=nums[i-1]){
                if(nums[i]>nums[i-1]){
                    incr++;
                    decr = 1;
                }
                else{
                    incr=1;
                    decr=1;
                }
            }
            else {
                if(nums[i]<nums[i-1]){
                    decr++;
                    incr = 1;
                }
                else{
                    incr=1;
                    decr = 1;
                }
            }
            ans = max({ans,incr,decr});
        }
        return ans;
    }
};