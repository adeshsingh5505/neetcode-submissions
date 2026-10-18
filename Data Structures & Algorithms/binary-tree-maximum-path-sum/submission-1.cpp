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
int maxi=-1e9;
    int  solve(TreeNode* root){
        if(root==NULL) return 0;
        int lsum=max(0,solve(root->left));
        int rsum=max(0,solve(root->right));
        maxi=max(maxi,lsum+rsum+root->val);
        return max(lsum,rsum)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        maxi=-1e9;
        solve(root);
        return maxi;
    }
};
