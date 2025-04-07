class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>res;
        int i = 0,j=0;
        while(j<nums.size()){
            while(!dq.empty() && nums[dq.back()] < nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);
            if(j-i+1<k){
                j++;
            }
            else{
                res.push_back(nums[dq.front()]);
                if(i == dq.front())dq.pop_front();
                i++;
                j++;
            }
        }
        return res;
    }
};