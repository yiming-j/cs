class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<int> sum(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }
        vector<vector<int>> dp(m, vector<int>(nums.size()));
        for (int j = 0; j < nums.size(); ++j) {
            dp[0][j] = sum[j + 1];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                dp[i][j] = INT_MAX;
                for (int k = 0; k <= j; ++k) {
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][k], sum[j + 1] - sum[k + 1]));
                }
            }
        }
        return dp[m - 1][nums.size() - 1];
    }
};