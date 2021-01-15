class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> cost(1 << n);
        for (int i = 0; i < (1 << n); ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    cost[i] += jobs[j];
                }
            }
        }
        vector<vector<int>> dp(k, vector<int>(1 << n));
        for (int j = 0; j < (1 << n); ++j) {
            dp[0][j] = cost[j];
        }
        for (int i = 1; i < k; ++i) {
            for (int j = 0; j < (1 << n); ++j) {
                dp[i][j] = INT_MAX;
                for (int s = j; s; s = (s - 1) & j) {
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][j - s], cost[s]));
                }
            }
        }
        return dp[k - 1][(1 << n) - 1];
    }
};