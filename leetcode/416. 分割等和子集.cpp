class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() < 2) {
            return false;
        }
        int sum = accumulate(nums.rbegin(), nums.rend(), 0);
        if ((sum & 1) == 1) {
            return false;
        }
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (const int &num: nums) {
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] | dp[j - num];
            }
            if (dp[target]) {
                return true;
            }
        }
        return dp[target];
    }
};