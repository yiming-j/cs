class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return {};
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ret;
        int dx = -1, dy = 1;
        int i = 0, j = 0;
        while (ret.size() < m * n) {
            ret.push_back(matrix[i][j]);
            int x = i + dx;
            int y = j + dy;
            if ((x < m && y < 0) || y == n) {
                x = i + 1;
                y = j;
                dx = -dx;
                dy = -dy;
            } else if ((x < 0 && y < n) || x == m) {
                x = i;
                y = j + 1;
                dx = -dx;
                dy = -dy;
            }
            i = x;
            j = y;
        }
        return ret;
    }
};