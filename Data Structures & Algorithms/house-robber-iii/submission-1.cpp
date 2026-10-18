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
private:
    int solve(TreeNode* root,unordered_map<TreeNode*,int> &dp){
        if(root==NULL){
            return 0;
        }
        if(dp[root]) return dp[root];
        //take
        int take=root->val;
        if(root->left){
            take+=solve(root->left->right,dp)+solve(root->left->left,dp);
        }
        if(root->right){
            take+=solve(root->right->right,dp)+solve(root->right->left,dp);
        }
        //not take
        int not_take=solve(root->left,dp)+solve(root->right,dp);

        return dp[root]=max(take,not_take);
    }
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> dp;
        return solve(root,dp);
    }
};