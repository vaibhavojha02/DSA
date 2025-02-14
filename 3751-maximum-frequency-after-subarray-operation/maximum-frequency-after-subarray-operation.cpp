class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int orignialCount = count(nums.begin(),nums.end(),k);
        int ans = 0;
        for(int i=1;i<=50;i++){
            if(i==k)continue;
            int curr = 0,maxcur = 0;
            for(int num : nums){
                if(num==i){
                    curr += 1;
                }
                else if(num==k){
                     curr -= 1;
                }
                else{
                    curr += 0;
                }
                curr = max(curr,0);
                maxcur = max(maxcur,curr);
            }
            ans = max(ans,maxcur);

        }
        return orignialCount + ans;

    }
};