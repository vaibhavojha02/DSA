class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<long long> dist(n, LONG_MAX);
        unordered_map< int, vector<pair<int, int>>>adj;
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
      priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        
        
        pq.push({0, 0});
        dist[0] = 0;
        vector< long long >pathcount(n,0);
        pathcount[0] = 1;
        while (!pq.empty()) {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(distance > dist[node])continue;

            for (auto i : adj[node]) {
                int w = i.second;
                int newnode = i.first;
                if (dist[node] + w < dist[newnode]){
                    dist[newnode] = dist[node] + w;
                    pathcount[newnode] = pathcount[node];
                    pq.push({dist[newnode], newnode});
                }
                else if(dist[node] + w == dist[newnode]){
                   pathcount[newnode] = (pathcount[newnode]+pathcount[node])%mod;
                }
            }
        }
        
        
        return pathcount[n-1];
        
        
    }
};