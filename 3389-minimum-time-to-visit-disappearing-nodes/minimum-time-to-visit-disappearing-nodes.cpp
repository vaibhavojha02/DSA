class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges,
                            vector<int>& disappear) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        dist[0] = 0;
        pq.push({0, 0}); // {dist,node};
        while (!pq.empty()) {
            int node = pq.top().second;
            int distance = pq.top().first;
            pq.pop();
            if (dist[node] < distance)
                continue;
            for (auto neigh : adj[node]) {

                int no = neigh.first;
                int d = neigh.second;
             
                if (d + distance < dist[no] && disappear[no] > d + distance) {
                    dist[no] = d + distance;
                    pq.push({dist[no], no});
                }
            }
        }
        vector<int> result(n, -1);
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX || dist[i] >= disappear[i]) {
                result[i] = -1;
            } else {
                result[i] = dist[i];
            }
            cout << dist[i] << " ";
        }
        return result;
    }
};