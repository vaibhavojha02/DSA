/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void inorder(vector<int>& trav, TreeNode* temp) {
        if (temp == nullptr)
            return;
        inorder(trav, temp->left);
        trav.push_back(temp->val);
        inorder(trav, temp->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> trav;
        inorder(trav, root);
        int n = queries.size();
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            int to_find = queries[i];
            int idx = lower_bound(trav.begin(), trav.end(), queries[i]) -
                      trav.begin();
            if (idx != trav.size() && trav[idx] == to_find) {
                ans[i] = {to_find, to_find};
            } else if (idx != trav.size() && trav[idx] != to_find) {
                if (idx != 0) {
                    ans[i] = {trav[idx - 1], trav[idx]};
                } else {
                    ans[i] = {-1, trav[idx]};
                }
            } else {
                ans[i] = {trav[idx - 1], -1};
            }
        }
        return ans;
    }
};