class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        if (n == 0 || n == 1) {
            return n;
        }
        unordered_map<int, int> map;
        vector<vector<int>> dp(n, vector<int>(n));
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int target = 2 * A[i] - A[j];
                if (map.find(target) != map.end()) {
                    dp[i][j] = dp[map[target]][i] + 1;
                    ret = max(ret, dp[i][j]);
                }
            }
            map[A[i]] = i;
        }
        return ret + 2;
    }
};