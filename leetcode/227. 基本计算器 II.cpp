class Solution {
public:
    int calculate(string s) {
        char op = '+';
        int num = 0;
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
                switch (op) {
                    int pre;
                    case '+':
                        stk.push(num);
                        break;
                    case '-':
                        stk.push(-num);
                        break;
                    case '*':
                        pre = stk.top();
                        stk.pop();
                        stk.push(pre * num);
                        break;
                    case '/' :
                        pre = stk.top();
                        stk.pop();
                        stk.push(pre / num);
                        break;
                }
                op = s[i];
                num = 0;
            }
        }
        int ans = 0;
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};