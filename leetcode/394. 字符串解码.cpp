class Solution {
public:
    string decodeString(string s) {
        stack<int> count;
        stack<string> str;
        string curr;
        int k = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (isalpha(c)) {
                curr += c;
            } else if (c == '[') {
                count.push(k);
                str.push(curr);
                k = 0;
                curr = "";
            } else if (c == ']') {
                for (int j = 0; j < count.top(); ++j) {
                    str.top() += curr;
                }
                curr = str.top();
                str.pop();
                count.pop();
            }
        }
        return curr;
    }
};