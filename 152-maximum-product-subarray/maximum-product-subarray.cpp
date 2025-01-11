class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int n = nums.size();
         int ans = INT_MIN;
         int suffix =1,prefix =1;
         for(int i =0;i<nums.size();i++){
            if(suffix==0)suffix = 1;
            if(prefix==0)prefix = 1;
            prefix = prefix*nums[i];
            suffix = suffix*nums[n-1-i];
            ans = max({ans,prefix,suffix});
         }
         return ans;
    }
};