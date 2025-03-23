class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        int to_be_removed = INT_MAX;
        int count = 0;
        for(int i =0;i<nums.size();i++){
            if( (nums[i]^k) > nums[i]){
                count++;
                sum += (nums[i]^k);
            }
            else{
                sum += nums[i];
            }
            to_be_removed = min(to_be_removed,abs(nums[i]-(nums[i]^k)));
        }
        if(count%2==0)return sum;
        return sum - to_be_removed;
    }
};