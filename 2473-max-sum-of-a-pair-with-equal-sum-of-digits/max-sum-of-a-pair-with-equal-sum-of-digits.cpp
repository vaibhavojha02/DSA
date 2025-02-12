class Solution {
public:
    int sumFromDigits(int x) {
        int sum = 0;
        while (x > 0) {
            sum += (x % 10);
            x = x / 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++){
            int temp = sumFromDigits(nums[i]);
            if (mp.find(temp) != mp.end()) {
                ans = max(ans, nums[i] + nums[mp[temp]]);
                if(nums[i]>nums[mp[temp]]){
                   mp[temp] = i;
                }
            }
            else{
                mp[temp] = i;
            }
           
        }
        return ans;
    }
};