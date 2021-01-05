class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ret;
        int i = 0, j = 1;
        while (j <= s.size()) {
            if (j < s.size() && s[j] == s[i]) {
                ++j;
            } else {
                if (j - i >= 3) {
                    ret.push_back({i, j - 1});
                }
                i = j;
                ++j;
            }
        }
        return ret;
    }
};