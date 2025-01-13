class Solution {
public:
    typedef pair<int, int> P;

    bool canAllReachZero(int n, unordered_map<int, vector<P>>& adj, int mid) {
        //BFS
        queue<int> que;
        vector<bool> visited(n, false);

        que.push(0);
        visited[0] = true;

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            for(P &p : adj[u]) {
                int v = p.first; //ngbr node
                int w = p.second;  //edge weight

                if(w <= mid && !visited[v]) {
                    visited[v] = true;
                    que.push(v);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(visited[i] == false) { //this ith node was not visited
                return false; //we could not visit all the nodes
            }
        }

        return true;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        unordered_map<int, vector<P>> adj;
        // u -> {(v1, w1), (v2,w2),... }

        int maxWt = 0;
        //Form the adj with reversed edge
        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[v].push_back({u, w}); //with reversed edge
            maxWt = max(maxWt, w);
        }

        //apply binary search on answer (weight)
        int result = INT_MAX; //invalid answer

        int l = 0;
        int r = maxWt;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(canAllReachZero(n, adj, mid) == true) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result == INT_MAX ? -1 : result;

    }
};