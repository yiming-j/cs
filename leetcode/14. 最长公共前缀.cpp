class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        string ans;
        size_t len = INT_MAX;
        for (const auto &str: strs) {
            len = min(len, str.size());
        }
        for (size_t i = 0; i < len; ++i) {
            char c = strs[0][i];
            for (const auto &str : strs) {
                if (str[i] != c) {
                    return ans;
                }
            }
            ans += c;
        }
        return ans;
    }
};