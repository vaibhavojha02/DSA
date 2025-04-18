class Solution {
public:
    vector<vector<int>> adj;

    void dfs(int node, vector<vector<int>>& mp, vector<int>& newParent, const string& s, const vector<int>& parent) {
        char ch = s[node];
        int idx = ch - 'a';

        if (!mp[idx].empty()) {
            newParent[node] = mp[idx].back();
        } else {
            newParent[node] = parent[node];
        }

        mp[idx].push_back(node);

        for (int child : adj[node]) {
            dfs(child, mp, newParent, s, parent);
        }

        mp[idx].pop_back();
    }

    int countSubtree(int node, vector<int>& ans, const vector<vector<int>>& tree) {
        int count = 1;
        for (int child : tree[node]) {
            count += countSubtree(child, ans, tree);
        }
        ans[node] = count;
        return count;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        adj.assign(n, {});

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<vector<int>> mp(26);             
        vector<int> newParent(n, -1);

        dfs(0, mp, newParent, s, parent);      

       
        vector<vector<int>> tree(n);
        for (int i = 1; i < n; i++) {
            if (newParent[i] != i && newParent[i] >= 0 && newParent[i] < n) {
                tree[newParent[i]].push_back(i);
            }
        }

        vector<int> ans(n, 1);
        countSubtree(0, ans, tree);
        return ans;
    }
};
