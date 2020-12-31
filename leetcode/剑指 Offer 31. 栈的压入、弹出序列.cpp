class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int i = 0, j = 0;
        stack<int> stk;
        while (j < n) {
            if (!stk.empty() && popped[j] == stk.top()) {
                ++j;
                stk.pop();
                continue;
            }
            if (i < n) {
                stk.push(pushed[i]);
                ++i;
            } else {
                break;
            }
        }
        return j == n;
    }
};