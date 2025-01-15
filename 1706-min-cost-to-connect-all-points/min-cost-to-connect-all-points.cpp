class Solution {
public:
    int distance(int a, int b, int c, int d) {
        return abs(a - c) + abs(b - d);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);  // Resize adj to n

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {  // Use j++
                int wt = distance(points[i][0], points[i][1], points[j][0], points[j][1]);
                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> vis(n, false);
        int sum = 0;

        pq.push({0, 0});  // {weight, node}
        
        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (vis[node]) continue;

            vis[node] = true;
            sum += wt;

            for (auto& it : adj[node]) {
                if (!vis[it.first]) {
                    pq.push({it.second, it.first});
                }
            }
        }

        return sum;
    }
};
