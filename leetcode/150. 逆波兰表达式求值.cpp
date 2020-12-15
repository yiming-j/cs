class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (const string& str : tokens) {
            if (str.size() == 1 && !isdigit(str[0])) {
                int r = s.top();
                s.pop();
                int l = s.top();
                s.pop();
                if (str[0] == '+') {
                    s.push(l + r);
                }
                if (str[0] == '-') {
                    s.push(l - r);
                }
                if (str[0] == '*') {
                    s.push(l * r);
                }
                if (str[0] == '/') {
                    s.push(l / r);
                }
            } else {
                s.push(stoi(str));
            }
        }
        return s.top();
    }
};