#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    int maxSum = INT_MIN;

    int maxGain(TreeNode* node) {
        if (!node) return 0;

        // Ignore paths with negative sums
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        // Path passing through current node as the highest root
        int currentPathSum = node->val + leftGain + rightGain;
        maxSum = max(maxSum, currentPathSum);

        // Return max gain if continuing the path upward to parent
        return node->val + max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};