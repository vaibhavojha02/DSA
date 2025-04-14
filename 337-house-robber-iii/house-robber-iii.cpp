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
    map<pair<TreeNode*,bool>,int>mp;
    int solve(TreeNode* root,bool take){
        if(root==nullptr)return 0;
        if(mp.find({root,take})!=mp.end()){
            return mp[{root,take}];
        }
        int takesum = 0,nottakesum = 0;;
        if(take==false)takesum += root->val + solve(root->left,true) + solve(root->right,true);
        nottakesum = solve(root->left,false) + solve(root->right,false);
        return mp[{root,take}] = max(takesum,nottakesum);
    }
    int rob(TreeNode* root) {
        mp.clear();
       return solve(root,false);
    }
};