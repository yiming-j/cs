class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == ' ' && (i == 0 || s[i - 1] == ' ')) {
                continue;
            }
            s[i++] = s[j];
        }
        if (s.back() == ' ') {
            --i;
        }
        s.erase(i);
        reverse(s.begin(), s.end());
        int start = 0;
        for (int end = 0; end <= s.size(); ++end) {
            if (end == s.size() || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        } 
        return s;
    }
};