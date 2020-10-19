class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int size = s.size();
        string ans = s;
        for (int i = 0; i < size; ++i) {
            s = s.substr(b, size) + s.substr(0, b);
            for (int j = 0; j < 10; ++j) {
                for (int o = 1; o < size; o += 2) {
                    s[o] += a;
                    if (s[o] > '9') {
                        s[o] = '0' + s[o] - '9' - 1;
                    }
                }
                if (b % 2) {
                    for (int k = 0; k < 10; ++k) {
                        for (int e = 0; e < size; e += 2) {
                            s[e] += a;
                            if (s[e] > '9') {
                                s[e] = '0' + s[e] - '9' - 1;
                            }
                        }
                        ans = min(ans, s);
                    }
                }
                ans = min(ans, s);
            }
        }
        return ans;
    }
};