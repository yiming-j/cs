class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0, j = 0;
        int cost = 0;
        int ret = 0;
        while (j < s.size()) {
            while (cost <= maxCost) {
                ret = max(ret, j - i);
                if (j >= s.size()) {
                    break;
                }
                cost += abs(s[j] - t[j]);
                ++j;
            }
            while (cost > maxCost) {
                cost -= abs(s[i] - t[i]);
                ++i;
            }
        }
        return ret;
    }
};