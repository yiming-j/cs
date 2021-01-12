class Solution {
private:
    vector<string> ret;
    
    bool isValid(const string& s) {
        int count = 0;
        for (const auto &c : s) {
            if (c == '(') {
                ++count;
            } else if (c == ')') {
                if (count == 0) {
                    return false;
                } else {
                    --count;
                }
            }
        }
        return count == 0;
    }
    
    void dfs(const string& s, int start, int l, int r) {
        if (l == 0 && r == 0 && isValid(s)) {
            ret.push_back(s);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (i > start && s[i] == s[i - 1]) {
                continue;
            }
            if (r > 0 && s[i] == ')') {
                string curr = s;
                curr.erase(i, 1);
                dfs(curr, i, l, r - 1);
            } else if (l > 0 && s[i] == '(') {
                string curr = s;
                curr.erase(i, 1);
                dfs(curr, i, l - 1, r);
            }
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        for (const char &c : s) {
            if (c == '(') {
                ++l;
            } else if (c == ')') {
                if (l == 0) {
                    ++r;
                } else {
                    --l;
                }
            }
        }
        dfs(s, 0, l, r);
        return ret;
    }
};