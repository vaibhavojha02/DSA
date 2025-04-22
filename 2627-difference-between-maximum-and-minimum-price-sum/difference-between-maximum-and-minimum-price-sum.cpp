class Solution {
public:
    unordered_map<int, vector<int>> adj;
    vector<long long> subtree_sum;
    long long maxpathsum(int node, int parent,
                         vector<int>& price) {

        long long mx = 0;
        for (auto ngbr : adj[node]) {
            if (ngbr == parent)continue;
            long long sum = maxpathsum(ngbr, node, price);
            mx = max(mx, sum);
        }

        return subtree_sum[node] = mx + price[node];
    }
    long long final_dif = 0;
    void rerootingdfs(int node, int parent, long long parent_contribution,
                      vector<int>& price) {
        long long max_sum = 0, second_max_sum = 0;
        int max_sum_node = -1;
        for (auto child : adj[node]) {
            if (child == parent)
                continue;
            if (subtree_sum[child] > max_sum) {
                second_max_sum = max_sum;
                max_sum = subtree_sum[child];
                max_sum_node = child;
            } else if (subtree_sum[child] > second_max_sum) {
                second_max_sum = subtree_sum[child];
            }
        }
        long long path1 = max_sum;
        long long path2 = parent_contribution;
        final_dif = max({final_dif, path1, path2});
        for (auto child : adj[node]) {
            if (child == parent)
                continue;
            if (child == max_sum_node) {

                rerootingdfs(child, node,
                             price[node] +
                                 max(parent_contribution, second_max_sum),
                             price);
            } else {

                rerootingdfs(child, node, price[node] + max(max_sum,parent_contribution), price);
            }
        }
    }

    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        adj.clear();
        for (int i = 0; i < n - 1; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        subtree_sum.resize(n);
        long long ans = 0;
        maxpathsum(0, -1,price);
        rerootingdfs(0, -1, 0LL, price);
        return final_dif;
    }
};
