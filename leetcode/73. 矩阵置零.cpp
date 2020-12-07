class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m, 1);
        vector<int> col(n, 1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            if (row[i] == 0) {
                for (int j = 0; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            if (col[j] == 0) {
                for (int i = 0; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};