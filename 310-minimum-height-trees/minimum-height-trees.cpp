class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        for (auto& i : edges) {
            int u = i[0];
            int v = i[1];
            indegree[u]++;
            indegree[v]++;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        while(n>2)
        {
          int size = q.size();
          n -= q.size();
          while(size--){
            int node = q.front();
            q.pop();
            for(auto i : adj[node]){
                indegree[i]--;
                if(indegree[i]==1){
                    q.push(i);
                }
            }
          }
        }
        vector<int>res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
        

    }
};