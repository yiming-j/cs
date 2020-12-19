class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int p = 0, i = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {
                ++i;
                continue;
            }
            if (p != 0) {
                s[p++] = ' ';
            }
            int j = i;
            while (j < s.size() && s[j] != ' ') {
                s[p++] = s[j++];
            }
            reverse(s.begin() + p - (j - i), s.begin() + p);
            i = j + 1;
        }
        s.erase(s.begin() + p, s.end());
        return s;
    }
};