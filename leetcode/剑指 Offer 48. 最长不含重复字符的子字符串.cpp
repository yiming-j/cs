class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int ret = 0;
        vector<int> pos(128, -1);
        while (j < s.size()) {
            while (j < s.size() && pos[s[j]] < i) {
                pos[s[j]] = j;
                ++j;
            }
            ret = max(ret, j - i);
            i = pos[s[j]] + 1;
        }
        return ret;
    }
};