class Solution {
public:
    int n;
    
    void Dijktra(vector<vector<pair<long long, long long>>>& adj, vector<long long>& temp, int start) {
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq; // {dist, node}
        temp[start] = 0;
        pq.push({0, start});
        
        while (!pq.empty()) {
            long long distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (distance > temp[node]) continue; // Skip if this is not the shortest path
            
            for (auto neigh : adj[node]) {
                if (distance + neigh.second < temp[neigh.first]) {
                    temp[neigh.first] = distance + neigh.second;
                    pq.push({temp[neigh.first], neigh.first});
                }
            }
        }
    }
    
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        this->n = n; // Correctly set n to the number of nodes
        vector<long long> source(n, LLONG_MAX);
        vector<long long> destination(n, LLONG_MAX);
        vector<vector<pair<long long, long long>>> adj(n);
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); // Since the graph is undirected
        }
        
        Dijktra(adj, source, 0);
        Dijktra(adj, destination, n - 1);
        
        long long minDist = source[n - 1];
        vector<bool> res(edges.size(), false);
        
        for (int i = 0; i < edges.size(); i++) {
            int first = edges[i][0];
            int second = edges[i][1];
            int wt = edges[i][2];
            
            // Check if the edge is part of the shortest path
             if ((source[first] != LLONG_MAX && destination[second] != LLONG_MAX &&
                 source[first] + wt + destination[second] == minDist) ||
                (destination[first] != LLONG_MAX && source[second] != LLONG_MAX &&
                 destination[first] + wt + source[second] == minDist)) {
                res[i] = true;
            }
        }
        
        return res;
    }
};
