class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        int i = 0;
        while (i < n && s[i] == ' ') {
            ++i;
        }
        if (i == n) {
            return 0;
        }
        int sign = 1;
        if (s[i] == '+') {
            sign = 1;
            ++i;
        } else if (s[i] == '-') {
            sign = -1;
            ++i;
        } else if (!isdigit(s[i])) {
            return 0;
        }
        if (!isdigit(s[i])) {
            return 0;
        }
        int ans = sign * (s[i] - '0');
        ++i;
        while (i < n && isdigit(s[i])) {
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && s[i] - '0' > 7)) {
                return INT_MAX;
            } else if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && s[i] - '0' > 8)) {
                return INT_MIN;
            } else {
                ans = ans * 10 + sign * (s[i] - '0');
            }
            ++i;
        }
        return ans;
    }
};