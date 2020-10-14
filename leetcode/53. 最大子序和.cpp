class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sub = nums[0];
        int dp = 0;
        for (const auto &num: nums) {
            dp = max(dp + num, num);
            max_sub = max(max_sub, dp);
        }
        return max_sub;
    }
};

/**
* dp[i] = max(dp[i - 1] + nums[i], nums[i])
*/