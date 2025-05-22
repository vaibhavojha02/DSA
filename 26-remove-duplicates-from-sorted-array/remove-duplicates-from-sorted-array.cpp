class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int last = nums.size()-1;
        int j = last;
        while(j>0){
            if(nums[j]==nums[j-1]){
                swap(nums[j],nums[last]);
                last--;
            }
            j--;
        }
        for(int i = 0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        sort(nums.begin(),nums.begin()+last+1);
        return last+1;
    }
};