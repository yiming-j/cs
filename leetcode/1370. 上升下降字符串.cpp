class Solution {
public:
    string sortString(string s) {
        vector<int> count(26, 0);
        for (const char &c : s) {
            ++count[c - 'a'];
        }
        string ans = "";
        while (ans.size() < s.size()) {
            for (int i = 0; i < 26; ++i) {
                if (count[i]) {
                    --count[i];
                    ans += 'a' + i;
                }
            }
            for (int i = 25; i >= 0; --i) {
                if (count[i]) {
                    --count[i];
                    ans += 'a' + i;
                }
            }
        }
        return ans;
    }
};