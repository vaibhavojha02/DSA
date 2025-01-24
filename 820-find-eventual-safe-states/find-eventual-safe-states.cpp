class Solution {
public:
    // Function to perform DFS to detect cycles
    bool dfs(vector<int>&vis, vector<int>&pathVis, vector<vector<int>>&graph, int node, vector<int>&check) {
        // Mark the current node as visited in the global 'vis' array and also in the path 'pathVis'
        vis[node] = 1;
        pathVis[node] = 1;
        
        // Initially mark the node as not safe (0)
        check[node] = 0;
        
        // Explore all the adjacent nodes of the current node
        for(auto i : graph[node]) {
            // If the adjacent node is not visited, do DFS on it
            if(vis[i] == -1) {
                if(dfs(vis, pathVis, graph, i, check)) return true; // If a cycle is found, return true
            }
            // If the adjacent node is visited and is part of the current path, a cycle is found
            else if(pathVis[i] != -1) {
                return true; // Return true indicating a cycle
            }
        }
        
        // Mark the current node as safe (1) after exploring all its adjacent nodes
        check[node] = 1;
        
        // Mark this node as no longer part of the current DFS path
        pathVis[node] = -1;
        
        return false; // No cycle found for this node
    }

    // Function to find all the eventual safe nodes
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size(); // Number of nodes in the graph
        
        // 'vis' keeps track of visited nodes (initialized to -1)
        vector<int>vis(v, -1);
        
        // 'pathVis' keeps track of nodes in the current DFS path (initialized to -1)
        vector<int>pathVis(v, -1);
        
        // 'check' keeps track of whether a node is eventually safe (1) or not (0)
        vector<int>check(v, 0);
        
        // Perform DFS for every node
        for(int i = 0; i < v; i++) {
            if(vis[i] == -1) { // If the node is not yet visited
                dfs(vis, pathVis, graph, i, check); // Perform DFS
            }
        }
        
        // Collect all the nodes that are eventually safe
        vector<int> result;
        for(int i = 0; i < v; i++) {
            if(check[i] == 1) result.push_back(i); // Only add safe nodes
        }
        
        return result; // Return the list of safe nodes
    }
};
