class Solution {
private:
    int maxSizeSlices(vector<int>& slices, int lo, int hi, int count) {
        vector<vector<int>> dp(hi - lo + 1, vector<int>(count + 1));
        dp[0][1] = slices[lo];
        dp[1][1] = max(slices[lo], slices[lo + 1]);
        for (int i = 2; i < hi - lo + 1; ++i) {
            for (int j = 1; j <= count; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - 1] + slices[lo + i]);
            }
        }
        return dp[hi - lo][count];
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return slices[0];
        }
        if (n == 2) {
            return max(slices[0], slices[1]);
        }
        return max(maxSizeSlices(slices, 0, n - 2, n / 3), maxSizeSlices(slices, 1, n - 1, n / 3));
    }
};