class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n));
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        for (int num = 1; num <= n * n;) {
            for (int j = left; j <= right; ++j) {
                ret[top][j] = num++;
            }
            for (int i = top + 1; i <= bottom; ++i) {
                ret[i][right] = num++;
            }
            if (top >= bottom || left >= right) {
                break;
            }
            for (int j = right - 1; j >= left; --j) {
                ret[bottom][j] = num++;
            }
            for (int i = bottom - 1; i > top; --i) {
                ret[i][left] = num++;
            }
            ++top, --bottom;
            ++left, --right;
        } 
        return ret;
    }
};