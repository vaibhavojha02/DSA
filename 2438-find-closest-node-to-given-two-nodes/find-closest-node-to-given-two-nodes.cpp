class Solution {
public:
    void dfs(vector<int>& edges, vector<int>& vis, int node,
             vector<int>& dist) {
        vis[node] = 1;
        int new_node = edges[node];
        if (new_node == -1 || vis[new_node] == 1)
            return;

        dist[new_node] = 1 + dist[node];
        dfs(edges, vis, new_node, dist);
        return;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int> vis1(n, -1);
        vector<int> vis2(n, -1);

        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);

        dist1[node1] = 0;
        dist2[node2] = 0;

        dfs(edges, vis1, node1, dist1);
        dfs(edges, vis2, node2, dist2);

        int minDistNode = -1;
        int minDistTillNow = INT_MAX;
        for (int i = 0; i < n; i++) {

            int maxD = max(dist1[i], dist2[i]);

            if (minDistTillNow > maxD) {
                minDistNode = i;
                minDistTillNow = maxD;
            }
        }

        return minDistNode;
    }
};