class Solution {
public:
    bool check(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right || left->val != right->val)
            return false;

        return check(left->left, right->right) &&
               check(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return check(root->left, root->right);
    }
};