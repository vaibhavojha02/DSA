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
    // From a leaf node, we can directly determine how to optimally distribute coins in the subtree because the only neighbor a leaf can exchange with is their parent.
public:
    int dfs(TreeNode* root, int& ops) {
        if (root == nullptr) {
            return 0;
        }
        int left = dfs(root->left, ops);
        int right = dfs(root->right, ops);
        ops += (abs(left) + abs(right));
        return left + right + root->val - 1;
    }
    int distributeCoins(TreeNode* root) {
        int ops = 0;
        dfs(root, ops);
        return ops;
    }
};