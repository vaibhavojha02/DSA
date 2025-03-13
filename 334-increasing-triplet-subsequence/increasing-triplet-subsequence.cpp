class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr;
        arr.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(arr.size()>=3)return true;
            if(nums[i]>arr.back()){
                arr.push_back(nums[i]);
            }
            else{
               int idx = lower_bound(arr.begin(),arr.end(),nums[i])-arr.begin();
               arr[idx] = nums[i];
            }
        }
        if(arr.size()>=3)return 1;
        return false;
    }
};