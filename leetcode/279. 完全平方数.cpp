class Solution {
public:
    int numSquares(int n) {
        vector<int> nums;
        for (int i = 1; i * i <= n; ++i) {
            nums.push_back(i * i);
        }
        vector<int> dp(n + 1, INT_MAX / 2);
        dp[0] = 0;
        for (int j = 1; j <= n; ++j) {
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] > j) {
                    break;
                }
                dp[j] = min(dp[j], dp[j - nums[i]] + 1);
            }
        }
        return dp[n];
    }
};