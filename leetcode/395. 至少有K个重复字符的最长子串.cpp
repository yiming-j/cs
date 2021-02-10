class Solution {
public:
    int longestSubstring(string s, int k) {
        if (k == 1) {
            return s.size();
        }
        if (s.size() < k) {
            return 0;
        }
        vector<int> count(26);
        for (const auto &c : s) {
            ++count[c - 'a'];
        }
        int i = 0;
        while (i < s.size()) {
            if (count[s[i] - 'a'] < k) {
                break;
            }
            ++i;
        }
        if (i == s.size()) {
            return s.size();
        }
        int l = longestSubstring(s.substr(0, i), k);
        ++i;
        while (i < s.size()) {
            if (count[s[i] - 'a'] < k) {
                ++i;
            } else {
                break;
            }
        }
        int r = longestSubstring(s.substr(i), k);
        return max(l, r);
    }
};