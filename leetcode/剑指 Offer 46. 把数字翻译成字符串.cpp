class Solution {
public:
    int translateNum(int num) {
        if (num < 10) {
            return 1;
        }
        string s = to_string(num);
        int n = s.size();
        vector<int> dp(n);
        dp[0] = 1;
        if (s[0] == '1' || (s[0] == '2' && s[1] <= '5')) {
            dp[1] = 2;
        } else {
            dp[1] = 1;
        }
        for (int i = 2; i < s.size(); ++i) {
            dp[i] = dp[i - 1];
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '5')) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n - 1];
    }
};