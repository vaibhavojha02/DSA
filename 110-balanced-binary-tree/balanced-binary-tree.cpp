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
    
    int maxHeight(TreeNode* root1) {
        if (root1 == nullptr)
            return 0;
        int left = maxHeight(root1->left);
        int right = maxHeight(root1->right);
        return 1 + max(left, right);
    }
    bool dfs(TreeNode* temp)
    {
        if (temp == nullptr)return true;


        int left =  maxHeight(temp->left);
        int right = maxHeight(temp->right);

        if(abs(left-right)>1)return false;

        if(dfs(temp->left)==false)return false;
        if(dfs(temp->right)==false)return false;
        return true;
    }
    bool isBalanced(TreeNode* root) { return dfs(root); }
};