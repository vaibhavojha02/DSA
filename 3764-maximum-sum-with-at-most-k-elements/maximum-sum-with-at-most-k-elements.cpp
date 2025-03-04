class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pq.push({grid[i][j], i});
            }
        }
        int selected = 0;
        long long sum = 0 ;
        if(k==0)return 0;
        
      long long ans=0;
        while(!pq.empty()){
            if(k== 0) break;
            if(limits[pq.top().second]>0){
                ans+=pq.top().first;
                limits[pq.top().second]--;
                k--;
            }
            pq.pop();
        }
        return ans;
    }
};