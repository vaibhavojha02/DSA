class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount  =0;
        int n = nums.size();
        vector<int>res(n);
        for(int i =0;i<nums.size();i++){
            if(nums[i]==0){
                zeroCount++;
            }
        }
        if(zeroCount>1)return res;
        vector<int>pref(n,1);
        vector<int>suff(n,1);
        for(int i =0;i<nums.size();i++){
            pref[i] = i > 0 ? pref[i-1]*nums[i] : nums[0];
            int j = n-i-1;
            suff[j] = j < n-1 ? suff[j+1] * nums[j] : nums[n-1];
            cout<<"["<<pref[i]<<" "<<suff[i]<<" ]";
        }
        for(int i = 0;i<n;i++){
            int left = i >0 ? pref[i-1] : 1;
            int right = i<n-1 ? suff[i+1] : 1;
            res[i] = left*right;
        }
        return res;

    }
};