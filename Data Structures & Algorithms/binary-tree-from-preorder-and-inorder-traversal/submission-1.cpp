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
    int solve2(vector<int> v, int k){
        for(int i=0;i<v.size();i++){
            if(v[i]==k) return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int isidx, int ieidx, int &pidx){
        if(ieidx<isidx) return NULL;
        int idx=solve2(inorder,preorder[pidx]);
        TreeNode* root=new TreeNode(preorder[pidx++]);
        root->left=solve(preorder,inorder,isidx,idx-1,pidx);
        root->right=solve(preorder,inorder,idx+1,ieidx,pidx);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pidx=0;
        return solve(preorder,inorder,0,inorder.size()-1,pidx);
    }
};
