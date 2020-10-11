class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int len = nums.size();
        vector<unordered_map<int, int>> dp(len);
        dp[0][nums[0]] += 1;
        dp[0][-nums[0]] += 1;
        for (int i = 1; i < len; ++i) {
            for (const auto &it: dp[i - 1]) {
                dp[i][it.first + nums[i]] += it.second;
                dp[i][it.first - nums[i]] += it.second;
            }
        }
        return dp[len - 1][S];
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.rbegin(), nums.rend(), 0);
        if (sum < S || (sum + S) % 2 == 1) {
            return 0;
        }
        int target = (sum + S) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (const auto &num : nums) {
            for (int j = target; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }
        return dp[target];
    }
};

/*
    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]]
*/