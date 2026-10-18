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
    void trv(TreeNode* root,vector<int> &v){
        if(root==NULL){
            v.push_back(0);
            return;
        }
        v.push_back(root->val);
        
        trv(root->right,v);
        
        trv(root->left,v);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> v1,v2;
        trv(p,v1);
        trv(q,v2);
        for(int i:v1) cout<<i<<" ";
        cout<<endl;
        for(int i:v2) cout<<i<<" ";
        cout<<endl;
        if(v1.size()!=v2.size()) return 0;
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=v2[i]) return 0;
        }
        return 1;
    }
};
