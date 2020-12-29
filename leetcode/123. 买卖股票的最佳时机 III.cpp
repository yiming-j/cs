class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2)));
        dp[0][0][0] = 0, dp[0][0][1] = -prices[0];
        dp[0][1][0] = INT_MIN / 2, dp[0][1][1] = INT_MIN / 2;
        dp[0][2][0] = INT_MIN / 2, dp[0][2][1] = INT_MIN / 2;
        for (int i = 1; i < n; ++i) {
            dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][0][0] - prices[i]);
            for (int j = 1; j <= 2; ++j) {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] - prices[i]);
            }
        } 
        return max({dp[n - 1][0][0], dp[n - 1][1][0], dp[n - 1][2][0]});
    }
};