class Solution {
private:
    vector<vector<vector<vector<string>>>> dp;
    vector<vector<int>> pal;
    vector<vector<string>> ret;
    
    void isPalindrome(const string &s) {
        for (int len = 1; len <= s.size(); ++len) {
            for (int i = 0, j = i + len - 1; j < s.size(); ++i, ++j) {
                if (len == 1) {
                    pal[i][j] = 1;
                } else if (len == 2) {
                    pal[i][j] = s[i] == s[j];
                } else {
                    pal[i][j] = pal[i + 1][j - 1] && s[i] == s[j];
                }
            }
        }
    }
    
    vector<vector<string>> dfs(const string &s, int lo, int hi) {
        if (lo == hi) {
            return dp[lo][hi] = {{string(1, s[lo])}};
        }
        if (!dp[lo][hi].empty()) {
            return dp[lo][hi];
        }
        for (int i = hi; i >= lo; --i) {
            if (!pal[i][hi]) {
                continue;
            }
            string right = s.substr(i, hi - i + 1);
            if (i == lo) {
                dp[lo][hi].push_back({right});
            } else {
                const auto &lefts = dfs(s, lo, i - 1);
                for (const auto &left : lefts) {
                    dp[lo][hi].push_back(left);
                    dp[lo][hi].back().push_back(right);
                }
            }
        }
        return dp[lo][hi];
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        pal = vector<vector<int>>(n, vector<int>(n));
        isPalindrome(s);
        dp = vector<vector<vector<vector<string>>>>(n, vector<vector<vector<string>>>(n));
        return dfs(s, 0, n - 1);
    }
};