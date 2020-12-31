class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> strs(numRows);
        int i = 0;
        while (i < s.size()) {
            for (int j = 0; j < numRows && i < s.size(); ++j) {
                strs[j].push_back(s[i++]);
            }
            for (int j = numRows - 2; j > 0 && i < s.size(); --j) {
                strs[j].push_back(s[i++]);
            }
        }
        string ret;
        for (auto &str : strs) {
            ret += str;
        }
        return ret;
    }
};