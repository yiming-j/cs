class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> s;
        for (int i = 0; i < num.size(); ++i) {
            char c = num[i];
            if (!s.empty() && c >= s.back()) {
                s.push_back(c);
            } else {
                while (k > 0 && !s.empty() && c < s.back()) {
                    s.pop_back();
                    --k;
                }
                if (c == '0' && s.empty()) {
                    continue;
                }
                s.push_back(c);
            }
        }
        while (k > 0 && !s.empty()) {
            s.pop_back();
            --k;
        }
        string ans = "";
        for (const char &c : s) {
            ans.push_back(c);
        }
        return ans == "" ? "0" : ans;
    }
};