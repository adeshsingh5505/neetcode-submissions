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
    void solve(TreeNode* root, int val){
        if(val<root->val){
            if(root->left==NULL){
                root->left=new TreeNode(val);
                return;
            } else{solve(root->left,val);}
        }
        if(val>root->val){
            if(root->right==NULL){
                root->right=new TreeNode(val);
                return;
            } else{solve(root->right,val);}
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //right->big
        //left->small
        if(!root) return new TreeNode(val);
        solve(root,val);
        return root;
    }
};