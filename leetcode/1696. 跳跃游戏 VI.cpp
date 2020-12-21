class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        deque<int> dq;
        dp[0] = nums[0];
        dq.push_back(0);
        for (int i = 1; i < n; ++i) {
            if (dq.front() < i - k) {
                dq.pop_front();
            }
            dp[i] = dp[dq.front()] + nums[i];
            while (!dq.empty() && dp[i] >= dp[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return dp[n - 1];
    }
};