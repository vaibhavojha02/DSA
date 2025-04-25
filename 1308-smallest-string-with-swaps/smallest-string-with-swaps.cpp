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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < pairs.size(); i++){
            unionDSU(pairs[i][0], pairs[i][1]);
        }
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[find(i)].push_back(i);
        }
        for (auto i : mp) {
            cout << i.first << ": ";
            for (int t : i.second) {
                cout << t << " ";
            }
            cout << endl;
        }
        for (auto i : mp) {
            string temp = "";
            for (int it : i.second)temp += s[it];
            sort(temp.begin(), temp.end());
            int k = 0;
            for (int t : i.second) {
                s[t] = temp[k++];
            }
        }
        return s;
    }
};