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
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int l=height(root->left);
        int r=height(root->right);
        return max(l,r)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return 1;
        if(abs(height(root->left) - height(root->right)) > 1) return false;
        return isBalanced(root->right) && isBalanced(root->left);
    }
};
