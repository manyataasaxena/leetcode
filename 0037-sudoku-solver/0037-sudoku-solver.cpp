class Solution {
public:
    bool solve(vector<vector<char>>& board,
               bool row[9][9],
               bool col[9][9],
               bool box[9][9]) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] != '.') continue;

                int b = (i / 3) * 3 + j / 3;

                for (int x = 0; x < 9; x++) {
                    if (row[i][x] || col[j][x] || box[b][x])
                        continue;

                    board[i][j] = '1' + x;
                    row[i][x] = col[j][x] = box[b][x] = true;

                    if (solve(board, row, col, box))
                        return true;

                    board[i][j] = '.';
                    row[i][x] = col[j][x] = box[b][x] = false;
                }

                return false;
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {}, col[9][9] = {}, box[9][9] = {};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int x = board[i][j] - '1';
                int b = (i / 3) * 3 + j / 3;

                row[i][x] = col[j][x] = box[b][x] = true;
            }
        }

        solve(board, row, col, box);
    }
};