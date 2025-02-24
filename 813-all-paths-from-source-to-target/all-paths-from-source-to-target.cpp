class Solution {
public:
    int n;
    void dfs(vector<vector<int>>& graph,vector<vector<int>>&ans,vector<int>&ds,int node)
    {
        if(node==n){
            
            ans.push_back(ds);
           return;
        }
        for(auto &ngbr : graph[node]){
            ds.push_back(ngbr);
            dfs(graph,ans,ds,ngbr);
            ds.pop_back();
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size()-1;
        vector<vector<int>>ans;
        vector<int>ds;
        ds.push_back(0);
        dfs(graph,ans,ds,0);
        return ans;
        
    }
};