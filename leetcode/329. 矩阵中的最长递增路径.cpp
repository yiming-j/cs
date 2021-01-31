class Solution {
private:
    static constexpr int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    vector<vector<int>> dp;
    int m, n;
    
    int dfs(int i, int j, const vector<vector<int>>& matrix) {
        if (dp[i][j]) {
            return dp[i][j];
        }
        dp[i][j] = 1;
        for (int k = 0; k < 4; ++k) {
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) {
                continue;
            }
            dp[i][j] = max(dp[i][j], dfs(x, y, matrix) + 1);
        }
        return dp[i][j];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        m = matrix.size(), n = matrix[0].size();
        dp = vector<vector<int>>(m, vector<int>(n));
        int ret = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ret = max(ret, dfs(i, j, matrix));
            }
        }
        return ret;
    }
};