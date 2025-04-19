class Solution {
public:
    unordered_map<int, vector<int>> mp;
    int dfs(int node, vector<int>& informTime) {
        int time = 0;
        for (auto i : mp[node]) {
            time = max(time,dfs(i, informTime));
        }
        return time+informTime[node];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager,
                     vector<int>& informTime) {
        mp.clear();
        // adjacency list created;
        for (int i = 0; i < manager.size(); i++) {
            if (manager[i] != -1) {
                mp[manager[i]].push_back(i);
            }
        }
        return dfs(headID, informTime);
    }
};