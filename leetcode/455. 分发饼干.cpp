class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ng = g.size(), ns = s.size();
        int i = 0, j = 0;
        int ret = 0;
        while (i < ng && j < ns) {
            if (g[i] <= s[j]) {
                ++ret;
                ++i;
            }
            ++j;
        }
        return ret;
    }
};