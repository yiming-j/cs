class Solution {
public:
    bool isValid(string s) {
        stack<char> char_stack;
        for (const char &c: s) {
            if (c == '(' || c == '[' || c == '{') {
                char_stack.push(c);
            } else if (c == ')') {
                if (char_stack.empty() || char_stack.top() != '(') {
                    return false;
                }
                char_stack.pop();
            } else if (c == ']') {
                if (char_stack.empty() || char_stack.top() != '[') {
                    return false;
                }
                char_stack.pop();
            } else if (c == '}') {
                if (char_stack.empty() || char_stack.top() != '{') {
                    return false;
                }
                char_stack.pop();
            }
        }
        return char_stack.empty();
    }
};