class Solution {
public:
    bool check(vector<int>&nums,int p,int mid){
        int count = 0;
        int i = 1;
        while(i<nums.size()){
            if(nums[i]-nums[i-1] <= mid){
                count++;
                i += 2;
            }
            else{
                i++;
            }
        }
        return count >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n==1)return 0;
        int ans = 0;
        int low = 0, high = nums[n-1] - nums[0];
        while(low <= high){
            int mid = low  + (high-low)/2;
            if(check(nums,p,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};