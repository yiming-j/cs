class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, INT_MIN / 2)));
        dp[0][0][0] = 0, dp[0][0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0][0] = 0;
            dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][0][0] - prices[i]);
            for (int j = 1; j <= k; ++j) {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] - prices[i]);
            }
        }
        int ret = 0;
        for (int j = 0; j <= k; ++j) {
            ret = max(ret, dp[n - 1][j][0]);
        }
        return ret;
    }
};