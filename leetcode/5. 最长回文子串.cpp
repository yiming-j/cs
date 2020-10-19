class Solution {
public:
    string palindrome(const string &s, int i, int j, int size) {
        while (i >= 0 && j < size) {
            if (s[i] != s[j]) {
                break;
            }      
            --i;
            ++j;
        }
        return s.substr(i + 1, j - i - 1);
    }
    string longestPalindrome(string s) {
        string ans;
        int size = s.size();
        for (int i = 0; i < size; ++i) {
            string odd = palindrome(s, i, i, size);
            string even = palindrome(s, i, i + 1, size);
            string curr = odd.size() > even.size() ? odd : even;
            ans = ans.size() > curr.size() ? ans : curr;
        }
        return ans;
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        vector<vector<int>> dp(size, vector<int>(size));
        string ans;
        int start;
        int max_len = 0;
        for (int len = 0; len < size; ++len) {
            for (int i = 0; i + len < size; ++i) {
                int j = i + len;
                if (len == 0) {
                    dp[i][j] = true;
                }
                else if (len == 1) {
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                }
                if (dp[i][j] && max_len < len + 1) {
                    max_len = len + 1;
                    start = i;
                }
            }
        }
        return ans = s.substr(start, max_len);
    }
};
