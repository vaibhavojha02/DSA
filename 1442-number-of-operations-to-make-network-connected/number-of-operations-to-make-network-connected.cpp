class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int i, vector<int>& parent) {
        if (i == parent[i]) {
            return i;
        }
        return parent[i] = find(parent[i], parent);
    }
    void unionDSU(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);
        if (x_parent == y_parent)
            return;
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent] += 1;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        int components = n;
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (auto& i : connections) {
            int x_parent = find(i[0], parent);
            int y_parent = find(i[1], parent);
            if (x_parent == y_parent) {
                continue;
            } else {
                unionDSU(i[0], i[1], parent, rank);
                components--;
            }
        }
        return components-1;
    }
};