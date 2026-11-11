class Solution {
    unordered_map<int, int> mp;
    int post;

    TreeNode* build(vector<int>& postorder, int l, int r) {
        if (l > r) return nullptr;

        int val = postorder[post--];
        TreeNode* root = new TreeNode(val);

        int mid = mp[val];

        root->right = build(postorder, mid + 1, r);
        root->left = build(postorder, l, mid - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        post = postorder.size() - 1;

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return build(postorder, 0, inorder.size() - 1);
    }
};