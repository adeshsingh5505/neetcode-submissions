class Solution {
private:
    bool solve(TreeNode* root, long min, long max) {
        if (root == nullptr) return true;
        if (root->val <= min || root->val >= max) return false;
        return solve(root->left, min, root->val) && solve(root->right, root->val, max);
    }

public:
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};
