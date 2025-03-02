class Solution {
public:
    vector<int>ans;
    vector<int> dfs(unordered_map<int,vector<int>>&adj,string& labels,int parent,int curr)
    {
          vector<int>freq(26,0);
          freq[labels[curr]-'a']++;
          for(auto i : adj[curr])
          {
            if(i!=parent)
            {
                vector<int>temp = dfs(adj,labels,curr,i);
                for(int i=0;i<26;i++)
                {
                    if(temp[i]!=0){
                        freq[i] += temp[i];
                    }
                }
            }
          }
          ans[curr] = freq[labels[curr]-'a'];
          return freq;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges,
                              string labels) {
        unordered_map<int, vector<int>> adj;
        for (auto i : edges) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ans.resize(n,0);
        vector<int>temp = dfs(adj,labels,-1,0);
        return ans;
       
    }
};