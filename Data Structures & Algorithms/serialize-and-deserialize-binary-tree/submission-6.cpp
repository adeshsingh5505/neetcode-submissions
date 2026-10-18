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

class Codec {
private:
    //LNR
    void inorder(TreeNode* root,string &ino){
        if(root==NULL) return;
        inorder(root->left,ino);
        ino+=to_string(root->val);
        ino+=',';
        inorder(root->right,ino);
    }
    //NLR
    void preorder(TreeNode* root, string &pre){
        if(root==NULL) return;
        pre+=to_string(root->val);
        pre+=',';
        preorder(root->left,pre);
        preorder(root->right,pre);
    }
    //finding index in inorder
    int index(vector<int> &v, int k, int s, int e){
        int idx=-1;
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]==k){
                v[i]=1e9;
                return i;
            }
        }
        return -1;
    }
    //creating tree
    TreeNode* solve(vector<int> &inorder, vector<int> &preorder, int s, int e, int &p){
        if(s>e) return NULL;
        TreeNode* root=new TreeNode(preorder[p]);
        int idx=index(inorder,preorder[p++],s,e);
        root->left=solve(inorder,preorder,s,idx-1,p);
        root->right=solve(inorder,preorder,idx+1,e,p);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string pre,ino;
        inorder(root,ino);
        preorder(root,pre);
        string ans=ino+"|"+pre;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        bool flag=0;
        int temp=0;
        vector<int> ino,pre;
        for(auto i: data){
            if(i==','||i=='|'){
                if(flag) pre.push_back(temp);
                else ino.push_back(temp);
                temp=0;
                if(i=='|') flag=1;
            }
            else temp=temp*10+(i-'0');
        }
        if(temp!=0 && data.back()=='0'){
            if(flag) pre.push_back(temp);
            else ino.push_back(temp);
            temp=0;
        }
        ino.pop_back();
        //cout<<index(ino,3,0,0)<<endl;
        for(auto i:ino) cout<<i<<" ";
        cout<<endl;
        for(auto i:pre) cout<<i<<" ";
        cout<<endl;

        int p=0;
        int e=ino.size()-1;
        return solve(ino,pre,0,e,p);
    }
};
