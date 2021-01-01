class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        int n = s.size();
        if (n <= 1) {
            return 1;
        }
        vector<int> dp(n);
        dp[0] = 1;
        dp[1] += s[1] != '0' ? 1 : 0;
        dp[1] += s[0] == '1' || s[0] == '2' && s[1] <= '6' ? 1 : 0;
        if (dp[1] == 0) {
            return 0;
        }
        for (int i = 2; i < n; ++i) {
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                dp[i] += dp[i - 2];
            } 
            if (s[i] != '0') {
                dp[i] += dp[i - 1];
            }
            if (dp[i] == 0) {
                return 0;
            }
        }
        return dp[n - 1];
    }
};