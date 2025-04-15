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
    // 0 for children is having camera
    //-1 children need camera
    // 1  children is covered think about yourself
    int dfs(TreeNode* root,int& cameras){
        if(root==nullptr)return 1;
        int left = dfs(root->left,cameras);
        int right = dfs(root->right,cameras);
        if(left==-1 || right==-1)
        {
            cameras++;
            return 0;
        }//three is need of camera so we will greedily rovide it
        if(left == 0 || right== 0)return 1;
        return -1;

    }
    int minCameraCover(TreeNode* root) {
        int cameras = 0;
        return dfs(root,cameras) == -1 ? cameras + 1 : cameras;
        
    }
};