class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n), diag1(2 * n), diag2(2 * n);

        function<void(int)> dfs = [&](int r) {
            if (r == n) {
                ans.push_back(board);
                return;
            }

            for (int c = 0; c < n; c++) {
                if (col[c] || diag1[r - c + n] || diag2[r + c])
                    continue;

                board[r][c] = 'Q';
                col[c] = diag1[r - c + n] = diag2[r + c] = true;

                dfs(r + 1);

                board[r][c] = '.';
                col[c] = diag1[r - c + n] = diag2[r + c] = false;
            }
        };

        dfs(0);
        return ans;
    }
};