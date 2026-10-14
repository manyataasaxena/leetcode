class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<bool> col(n), diag1(2 * n), diag2(2 * n);

        function<void(int)> dfs = [&](int r) {
            if (r == n) {
                ans++;
                return;
            }

            for (int c = 0; c < n; c++) {
                if (col[c] || diag1[r - c + n] || diag2[r + c])
                    continue;

                col[c] = diag1[r - c + n] = diag2[r + c] = true;
                dfs(r + 1);
                col[c] = diag1[r - c + n] = diag2[r + c] = false;
            }
        };

        dfs(0);
        return ans;
    }
};