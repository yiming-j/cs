class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> c2s;
        unordered_map<string, char> s2c;
        int n = s.size();
        int i = 0;
        for (const char& c: pattern) {
            string temp = "";
            while (i < n && s[i] != ' ') {
                temp += s[i];
                ++i;
            }
            ++i;
            if (!c2s.count(c) && !s2c.count(temp)) {
                c2s[c] = temp;
                s2c[temp] = c;
                continue;
            }
            if (c2s[c] != temp || s2c[temp] != c) {
                return false;
            }
        }
        return i == n + 1;
    }
};