class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        for (int i = 0; i < m; ++i) {
            if (A[i][0] == 0) {
                for (int j = 0; j < n; ++j) {
                    A[i][j] = 1 - A[i][j];
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            int count0 = 0;
            for (int i = 0; i < m; ++i) {
                if (A[i][j] == 0) {
                    ++count0;
                }
            }
            if (count0 * 2 < m) {
                continue;
            }
            for (int i = 0; i < m; ++i) {
                A[i][j] = 1 - A[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            int b = 0;
            for (int j = 0; j < n; ++j) {
                b = (b << 1) + A[i][j];
            }
            ans += b;
        }
        return ans;
    }
};