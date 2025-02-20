class Solution {
public:
    unordered_map<string,int>mp;
    void solve(string temp,int idx,int n){
         if(idx>=n){
            mp[temp]++;
            return;
         }
         temp += '1';
         solve(temp,idx+1,n);
         temp.pop_back();
         temp += '0';
         solve(temp,idx+1,n);
         return;

    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        mp.clear();
        solve("",0,n);
        for(int i=0;i<nums.size();i++){
            mp.erase(nums[i]);
        }
        auto it = mp.begin();
        return it->first;
    }
};