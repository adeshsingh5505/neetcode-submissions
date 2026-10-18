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
    void trv(TreeNode* root, int &cnt, int maxi){
        if(root==NULL){
            return;
        }
        if(root->val>=maxi){
            cnt++;
            maxi=root->val;
        }
        trv(root->left,cnt,maxi);
        trv(root->right,cnt,maxi);
    }
public:
    int goodNodes(TreeNode* root) {
        int cnt=0;
        trv(root,cnt,root->val);
        return cnt;
    }
};
