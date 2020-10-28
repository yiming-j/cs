class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (n == 0) {
            return 0;
        }
        if (m == 0) {
            return -1;
        }
        for (int i = 0; i <= m - n; ++i) {
            int j = 0;
            for (; j < n; ++j) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == n) {
                return i;
            }
        }
        return -1;
    }
};