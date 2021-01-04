class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        vector<int> temp(n + 2);
        temp[0] = 1, temp[n + 1] = 1;
        copy(nums.begin(), nums.end(), temp.begin() + 1);
        for (int len = 3; len <= n + 2; ++len) {
            for (int i = 0, j = i + len - 1; j < n + 2; ++i, ++j) {
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = max(dp[i][j], temp[i] * temp[k] * temp[j] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][n + 1];
    }
};