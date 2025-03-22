class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        for(int i = 1;i<nums.size()-1;i++){
            if(nums[i]*2 == (nums[i+1] + nums[i-1])){
                if(nums[i-1]>nums[i]){
                    swap(nums[i],nums[i-1]);
                }
                else{
                    swap(nums[i],nums[i+1]);
                }
            }
        }
        for(int i = nums.size()-2;i>=1;i--){
            if(nums[i]*2 == (nums[i+1] + nums[i-1])){
                if(nums[i-1]>nums[i]){
                    swap(nums[i],nums[i-1]);
                }
                else{
                    swap(nums[i],nums[i+1]);
                }
            }
        }
        return nums;
    }
};