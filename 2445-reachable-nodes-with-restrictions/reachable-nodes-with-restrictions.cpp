class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&mp,int node,vector<int>&visited,unordered_set<int>&deads){
        visited[node] = 1;
        for(auto ngbr : mp[node]){
             if(deads.find(ngbr)==deads.end() && visited[ngbr]==-1){
                dfs(mp,ngbr,visited,deads);
             }
        }
        return;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int>deads(restricted.begin(),restricted.end());
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<int>visited(n,-1);
        dfs(mp,0,visited,deads);
        int res = n;
        for(int i=0;i<n;i++){
            if(visited[i]==-1)res--;
        }
        return res;


    }
};