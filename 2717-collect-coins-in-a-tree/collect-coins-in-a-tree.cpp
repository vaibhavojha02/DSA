class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size(); // nver use
        vector<int> indegree(n);
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1 && coins[i] == 0) {
                q.push(i);
            }
        }
        int remainingnodes = n;
        while (!q.empty()) {
            int t = q.size();
            while (t--) {
                int node = q.front();
                q.pop();
                remainingnodes--;
                for (auto& ngbr : adj[node]) {
                    auto parent =find(adj[node].begin(), adj[node].end(), ngbr);
                    auto child = find(adj[ngbr].begin(), adj[ngbr].end(), node);

                    adj[ngbr].erase(child);
                    adj[node].erase(parent);
                    indegree[ngbr]--;
                    indegree[node]--;
                    if (coins[ngbr] == 0 && indegree[ngbr] == 1) {
                        q.push(ngbr);
                    }
                }
            }
        }
        q = queue<int>();
        for (int i = 0; i < n; i++) {
            if(indegree[i]==1 && coins[i]==1){
               q.push(i);
            }
        }
        int t = 2;
        while(t--){
            int k = q.size();
            while(k--){
                int node = q.front();
                q.pop();
                remainingnodes--;
                for(auto ngbr : adj[node]){
                    auto parent = find(adj[node].begin(),adj[node].end(),ngbr);
                    auto child = find(adj[ngbr].begin(),adj[ngbr].end(),node);
                    adj[node].erase(parent);
                    adj[ngbr].erase(child);
                    indegree[node]--;
                    indegree[ngbr]--;
                    if(indegree[ngbr]==1) {
                        q.push(ngbr);
                    }
                }
            }
        }
        return max(0,2*(remainingnodes-1));
    }
};
