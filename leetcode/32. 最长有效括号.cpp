class Solution {
public:
    int longestValidParentheses(string s) {
        int ret = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                if (!stk.empty() && stk.top() >= 0 && s[stk.top()] == '(') {
                    stk.pop();
                    ret = max(ret, i - stk.top());  
                } else {
                    while (!stk.empty()) {
                        stk.pop();
                    }
                    stk.push(i);
                }
            }
        }
        return ret;
    } 
};

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        vector<int> invalid(s.size());
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                if (!stk.empty()) {
                    stk.pop();
                } else {
                    invalid[i] = 1;
                }
            }
        }
        while (!stk.empty()) {
            invalid[stk.top()] = 1;
            stk.pop();
        }
        int ret = 0;
        int curr = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (invalid[i]) {
                curr = 0;
            } else {
                ++curr;
                ret = max(ret, curr);
            }
        }
        return ret;
    }
};