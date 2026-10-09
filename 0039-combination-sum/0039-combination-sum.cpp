class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;

        function<void(int, int)> dfs = [&](int i, int sum) {
            if (sum == target) {
                ans.push_back(cur);
                return;
            }

            if (i == candidates.size() || sum > target) return;

            cur.push_back(candidates[i]);
            dfs(i, sum + candidates[i]);  // Reuse same element
            cur.pop_back();

            dfs(i + 1, sum);  // Skip element
        };

        dfs(0, 0);
        return ans;
    }
};