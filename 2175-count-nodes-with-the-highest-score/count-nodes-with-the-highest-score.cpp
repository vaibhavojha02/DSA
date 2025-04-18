class Solution {
public:
    vector<vector<int>> adj;
    unordered_map<long long, int> mp;
    int n;
    
    int dfs(int node) {
        long long product = 1;
        int totalSubtreeSize = 0;

        for (int child : adj[node]) {
            int childSize = dfs(child);
            product *= childSize;
            totalSubtreeSize += childSize;
        }

        int remaining = n - totalSubtreeSize - 1;
        if (remaining > 0) product *= remaining;

        mp[product]++;
        return totalSubtreeSize + 1;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        adj.clear();
        adj.resize(n);
        mp.clear();

        for (int i = 1; i < n; i++) {
            adj[parents[i]].push_back(i);
        }

        dfs(0);

        long long maxScore = 0;
        for (auto& [score, freq] : mp) {
            maxScore = max(maxScore, score);
        }

        return mp[maxScore];
    }
};
