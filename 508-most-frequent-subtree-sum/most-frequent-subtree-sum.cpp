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
    unordered_map<int, int> mp;
    int maxfreq = 0;
    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int leftsubtreesum = dfs(root->left);
        int rightSubreesum = dfs(root->right);
         
        int currsum = leftsubtreesum + root->val + rightSubreesum;
        mp[currsum]++;
        maxfreq = max(maxfreq,mp[currsum]);
        return currsum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        mp.clear();
        dfs(root);
        
        vector<int>res;
        for(auto i : mp){
            if(i.second == maxfreq){
                res.push_back(i.first);
            }
        }
        return res;

        
    }
};