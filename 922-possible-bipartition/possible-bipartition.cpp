class Solution {
public:
    bool isBipartite(unordered_map<int, vector<int>>&adj,int node,int parent,vector<int>&color){
        color[node] = !parent;
        for(auto &ngbr : adj[node]){
            if(color[ngbr]==-1){
                if(isBipartite(adj,ngbr,!parent,color)==false)return false;
            }
            else if(color[ngbr] == !parent)return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n + 1, -1);
        unordered_map<int, vector<int>> adj;
        for (auto& vec : dislikes) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 1;i<=n;i++){
            if(color[i]==-1){
             if(isBipartite(adj,i,0,color)==false)return false;
            }
        }
        return true;

    }
};