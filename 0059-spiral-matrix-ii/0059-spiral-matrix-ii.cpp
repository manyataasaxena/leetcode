class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int val = 1;

        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++)
                ans[top][j] = val++;
            top++;

            for (int i = top; i <= bottom; i++)
                ans[i][right] = val++;
            right--;

            for (int j = right; top <= bottom && j >= left; j--)
                ans[bottom][j] = val++;
            bottom--;

            for (int i = bottom; left <= right && i >= top; i--)
                ans[i][left] = val++;
            left++;
        }

        return ans;
    }
};