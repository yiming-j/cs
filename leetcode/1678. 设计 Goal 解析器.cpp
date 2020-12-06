class Solution {
public:
    string interpret(string command) {
        string ans = "";
        int n = command.size();
        for (int i = 0; i < n; ++i) {
            if (command[i] == '(') {
                if (command[i + 1] == ')') {
                    ans += 'o';
                    ++i;
                } else {
                    ans += "al";
                    i += 3;
                }
            } else if (command[i] == 'G') {
                ans += 'G';
            }
        }
        return ans;
    }
};