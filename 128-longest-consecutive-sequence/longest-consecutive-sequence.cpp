class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        int longest = 0;
        for(auto i : mp){
            int length = 0;
            int ele = i.first;
            if(mp.find(ele-1)==mp.end())
            {
                while(mp.find(ele)!=mp.end()){
                    ele += 1;
                    length++;
                }
            }
            longest = max(longest,length);
        }
        return longest;
    }
};