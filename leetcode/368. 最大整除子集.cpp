class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i].push_back(nums[i]);
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0 && dp[i].size() < dp[j].size() + 1) {
                    dp[i] = dp[j];
                    dp[i].push_back(nums[i]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs.size() < rhs.size();
        });
    }
};