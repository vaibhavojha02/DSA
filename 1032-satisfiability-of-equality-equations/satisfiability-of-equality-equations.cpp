class Solution {
public:
    vector<int> parent;
    vector<int> rank;
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
        } else if (rank[x_parent] > rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent] += 1;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        for (string& equation : equations) {
            int x = equation[0] - 'a';
            int y = equation[3] - 'a';
            if (equation[1] == '=') {
                unionDSU(x, y, parent, rank);
            }
        }
        for (string& equation : equations) {
            int x = equation[0] - 'a';
            int y = equation[3] - 'a';

            if (equation[1] == '!') {
                int x_parent = find(x, parent);
                int y_parent = find(y, parent);
                if (x_parent == y_parent)
                    return false;
            }
        }
        return true;
    }
};