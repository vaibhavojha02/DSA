class Solution {
public: 
    int dfs(unordered_map<int,vector<int>>& adj, int& result, int parent_node, string& s, int node) {
        int largest = 0, second_largest = 0;
        
        for (auto it : adj[node]) {
            if (it == parent_node) continue;  // Avoid revisiting the parent
            
            int distance = dfs(adj, result, node, s, it);
            
            // Only consider children with different characters
            if (s[it] != s[node]) {
                if (distance > largest) {
                    second_largest = largest;
                    largest = distance;
                } else if (distance > second_largest) {
                    second_largest = distance;
                }
            }
        }
        
        // Update the result: Longest path passing through this node
        result = max(result, 1 + largest + second_largest);
        
        // Return the longest valid path ending at this node
        return 1 + largest;
    }

    int longestPath(vector<int>& parent, string s) {
        unordered_map<int, vector<int>> adj;
        
        for (int i = 1; i < parent.size(); i++) {  // Start from 1 since 0 has no parent
            int u = i, v = parent[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int result = 1;
        dfs(adj, result, -1, s, 0);
        return result;
    }
};
