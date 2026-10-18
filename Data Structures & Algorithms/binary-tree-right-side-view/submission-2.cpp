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
    vector<vector<int>> lot(TreeNode* root){
        vector<vector<int>> res;
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> ans;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* temp=q.front();
                q.pop();
                ans.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            res.push_back(ans);
        }
        return res;
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> res=lot(root);
        int j=0;
        vector<int> ans;
        int n=res.size();
        while(j<n){
            int n=res[j].size()-1;
            ans.push_back(res[j][n]);
            j++;
        }
        return ans;
    }
};
