class Solution {
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(TreeNode* root, int sum) {
        if (!root) return;

        path.push_back(root->val);
        sum -= root->val;

        if (!root->left && !root->right && sum == 0)
            ans.push_back(path);
        else {
            dfs(root->left, sum);
            dfs(root->right, sum);
        }

        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ans;
    }
};