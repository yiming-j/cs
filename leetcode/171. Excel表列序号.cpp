class Solution {
public:
    int titleToNumber(string s) {
        long long ans = 0;
        for (const char& c : s) {
            ans = ans * 26 + c - 'A' + 1;
        }
        return ans;
    }
};