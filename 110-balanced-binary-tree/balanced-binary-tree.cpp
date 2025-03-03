/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool flag = false;
    int solve(TreeNode* temp){
        if(temp==nullptr)return 0;
        int left = solve(temp->left);
        int right = solve(temp->right);
        if(abs(left-right)>1){
            flag = true;
        }
        return 1 + max(left,right);
    }
    bool isBalanced(TreeNode* root)
    {
        solve(root);
        return !flag;
    }
};