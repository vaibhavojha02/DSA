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
    void dfs(TreeNode* root,int& ans,string temp){
        if(root->left==nullptr && root->right==nullptr)
        {
            temp += to_string(root->val);
            int t = stoi(temp);
            ans += t;
            return;
        }
        temp += to_string(root->val);
        if(root->left)dfs(root->left,ans,temp);
        if(root->right)dfs(root->right,ans,temp);
        }
    int sumNumbers(TreeNode* root) {
        int ans  = 0;
        string temp = "";
        dfs(root,ans,temp);
        return ans;
    }
};