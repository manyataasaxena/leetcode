class Solution {
private:
    int dfs(TreeNode* node, int currentSum) {
        if (!node) return 0;

        currentSum = currentSum * 10 + node->val;

        // Leaf node reached: return the formed root-to-leaf number
        if (!node->left && !node->right) {
            return currentSum;
        }

        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }

public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};