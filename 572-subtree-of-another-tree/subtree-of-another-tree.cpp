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
    string sub = "";
    unordered_map<string, int> mp;
    string generateallsubtree(TreeNode* root) {
        if (root == nullptr) {
            return "N";
        }
        string s = to_string(root->val) + generateallsubtree(root->left) +
                   generateallsubtree(root->right);
        cout << s << " ";
        mp[s]++;
        return s;
    }
    void dfs(TreeNode* subroot) {
        if (subroot == nullptr) {
            sub += "N";
            return;
        }
        sub += to_string(subroot->val);
        dfs(subroot->left);
        dfs(subroot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        mp.clear();
        dfs(subRoot);
        generateallsubtree(root);

        if (mp.find(sub) != mp.end()) {
            return true;
        }
        return false;
    }
};