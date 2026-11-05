class Solution {
public:
    vector<TreeNode*> generate(int start, int end) {
        if (start > end) return {nullptr};

        vector<TreeNode*> ans;

        for (int i = start; i <= end; i++) {
            auto leftTrees = generate(start, i - 1);
            auto rightTrees = generate(i + 1, end);

            for (auto l : leftTrees) {
                for (auto r : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generate(1, n);
    }
};