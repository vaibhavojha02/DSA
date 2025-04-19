class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        map<int,int>temp;
        
        for (int i = 0; i < n; i++) {
            temp[intervals[i][0]] = i;
        }
        vector<int> res(n);
        
        
        for (int i = 0; i < n; i++) {
            auto idx = temp.lower_bound(intervals[i][1]);
            if (idx == temp.end()) {
                res[i] = -1; 
            } else {
                res[i] = (*idx).second;
            }
        }
        return res;
    }
};