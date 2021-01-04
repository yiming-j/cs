class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                if (len == 1) {
                    dp[i][j] = 1;
                } else if (len == 2) {
                    dp[i][j] = s[i] == s[j] ? 2 : 1;
                } else {
                    if (s[i] == s[j]) {
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                    } else {
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};