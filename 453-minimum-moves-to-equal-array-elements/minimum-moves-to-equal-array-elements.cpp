class Solution {
public:
    int minMoves(vector<int>& nums){
        int ele = *min_element(nums.begin(),nums.end());
        int sum = accumulate(nums.begin(),nums.end(),0);
        return sum - ele*nums.size();
    }
};