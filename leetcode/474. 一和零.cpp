class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int len = strs.size();
        for (int i = 0; i < len; ++i) {
            int num_0 = count(strs[i].rbegin(), strs[i].rend(), '0');
            int num_1 = count(strs[i].rbegin(), strs[i].rend(), '1');
            for (int j = m; j >= num_0; --j) {
                for (int k = n; k >= num_1; --k) {
                    dp[j][k] = max(dp[j][k], dp[j - num_0][k - num_1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};