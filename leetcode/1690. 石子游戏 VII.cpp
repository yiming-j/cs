class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        function<int(int, int, int)> dfs = [&] (int l, int r, int sum) {
            if (l >= r) {
                return 0;
            }
            if (dp[l][r] == INT_MAX) {
                dp[l][r] = max(sum - stones[l] - dfs(l + 1, r, sum - stones[l]),
                               sum - stones[r] - dfs(l, r - 1, sum - stones[r]));
            }
            return dp[l][r];
        };
        
        return dfs(0, stones.size() - 1, accumulate(stones.begin(), stones.end(), 0));
    }
};

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> sum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = stones[i] + sum[i];
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 2; len <= n; ++ len) {
            for (int l = 0, r = l + len - 1; r < n; ++l, ++r) {
                dp[l][r] = max(sum[r + 1] - sum[l + 1] - dp[l + 1][r],
                               sum[r] - sum[l] - dp[l][r - 1]);
            }
        }
        return dp[0][n - 1];
    }
};