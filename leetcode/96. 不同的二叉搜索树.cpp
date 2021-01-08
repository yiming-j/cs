class Solution {
public:
    int numTrees(int n) {
        vector<vector<int>> dp(n, vector<int>(n));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                if (len == 1) {
                    dp[i][j] = 1;
                } else {
                    for (int k = i; k <= j; ++k) {
                        if (k == i) {
                            dp[i][j] += dp[k + 1][j];
                        } else if (k == j) {
                            dp[i][j] += dp[i][k - 1];
                        } else {
                            dp[i][j] += dp[i][k - 1] * dp[k + 1][j];                         
                        }
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};