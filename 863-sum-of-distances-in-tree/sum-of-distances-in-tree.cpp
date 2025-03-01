class Solution {
public:
    vector<int> subNodes;  // Stores subtree sizes

    void dfs(int level, unordered_map<int, vector<int>>& adj, vector<int>& vis,
             int node, int& ans) {
        vis[node] = 1;
        subNodes[node] = 1; // Include itself
        for (auto& i : adj[node]) {
            if (vis[i] == -1) {
                dfs(level + 1, adj, vis, i, ans);
                ans += level; // Sum distances from root
                subNodes[node] += subNodes[i];  // Accumulate subtree sizes
            }
        }
    }

    void dfs2(int node, unordered_map<int, vector<int>>& adj, vector<int>& vis, vector<int>& res, int n) {
        vis[node] = 1;
        for (auto& i : adj[node]) {
            if (vis[i] == -1) {
                res[i] = res[node] + (n - 2 * subNodes[i]);  // Adjust distances
                dfs2(i, adj, vis, res, n);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& i : edges) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        subNodes.resize(n);
        vector<int> res(n);
        vector<int> vis(n, -1);

        // First DFS: Calculate distances from root (0) and subtree sizes
        dfs(1, adj, vis, 0, ans);
        res[0] = ans;

        // Reset visited array for second DFS
        fill(vis.begin(), vis.end(), -1);

        // Second DFS: Compute distances for all other nodes
        dfs2(0, adj, vis, res, n);

        return res;
    }
};
