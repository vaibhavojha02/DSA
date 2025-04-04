class Solution {
public:
    int cnt = 0;
    void DFS(int source, vector<vector<pair<int, int>>>& adj, int parent, int len, int signalSpeed){
        if(len % signalSpeed == 0)
            cnt++;
        for(auto [v, weight] : adj[source]){
            if(v != parent)
                DFS(v, adj, source, len + weight, signalSpeed);
        }
    }
    
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<int> count(n);
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : edges){
            int x = it[0], y = it[1], w = it[2];
            adj[x].push_back({y, w});
            adj[y].push_back({x, w});
        }
        for(int node = 0 ; node < n ; node++){
            int ans = 0, prev = 0;
            for(auto [source, weight] : adj[node]){
                cnt = 0;
                DFS(source, adj, node, weight, signalSpeed);
                ans += prev * cnt;
                prev += cnt;
            }
            count[node] = ans;
        }
        return count;
    } 
};