class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        constexpr int maxValue = 0x3f3f3f3f;
        vector<int> dp(amount + 1, maxValue);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (const int &coin : coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == maxValue ? -1 : dp[amount];
    }
};