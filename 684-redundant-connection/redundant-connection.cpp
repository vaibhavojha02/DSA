class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int node)
    {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = find(parent[node]);
    }
    void unionDSU(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent) {
            return;
        }
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
        return;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        rank.resize(n, 0);
        parent.resize(n);
        vector<int> res(2);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < edges.size(); i++) {
            int x = edges[i][0]-1;
            int y = edges[i][1]-1;
            int x_parent = find(x);
            int y_parent = find(y);
            if (x_parent == y_parent) {
                  return {x+1,y+1};
            }
            unionDSU(x, y);
            

        }
        return {};
    }
};