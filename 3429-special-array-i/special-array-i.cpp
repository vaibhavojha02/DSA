class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool parity = nums[0]%2;
        for(int i=1;i<nums.size();i++){
            if(nums[i]%2==parity){
                return false;
            }
            else{
                parity = nums[i]%2;
            }
        }
        return true;
    }
};