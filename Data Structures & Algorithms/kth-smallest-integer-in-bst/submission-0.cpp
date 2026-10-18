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
    void trv(TreeNode* root, vector<int> &v){
        if(root==NULL){
            return;
        }
        v.push_back(root->val);
        trv(root->left,v);
        trv(root->right,v);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        trv(root,v);
        sort(v.begin(),v.end());
        for(int i:v){
            cout<<i<<" ";
        }
        return v[k-1];
    }
};
