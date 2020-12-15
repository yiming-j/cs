class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        vector<int> ans;
        while (ans.size() < m * n) {
            for (int j = left; j <= right; ++j) {
                ans.push_back(matrix[top][j]);
            }
            for (int i = top + 1; i <= bottom; ++i) {
                ans.push_back(matrix[i][right]);
            }
            if (left >= right || top >= bottom) {
                break;
            }
            for (int j = right - 1; j >= left; --j) {
                ans.push_back(matrix[bottom][j]);
            }
            for (int i = bottom - 1; i > top; --i) {
                ans.push_back(matrix[i][left]);
            }
            ++left;
            ++top;
            --right;
            --bottom;
        }
        return ans;
    }
};