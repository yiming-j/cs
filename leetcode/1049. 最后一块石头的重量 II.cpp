class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.rbegin(), stones.rend(), 0);
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        for (const int &stone: stones) {
            for (int j = target; j >= stone; --j) {
                dp[j] = max(dp[j], dp[j - stone] + stone);
            }
        }
        return sum - 2 * dp[target];
    }
};

/*
    dp[0][0] = 0;
    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]) 
*/