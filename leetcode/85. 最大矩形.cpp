class Solution {
private:
    int maxArea(vector<int> &nums) {
        int n = nums.size();
        stack<int> stk;
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            int r = stk.empty() ? -1 : stk.top();
            while (!stk.empty() && nums[i] < nums[stk.top()]) {
                int h = nums[stk.top()];
                stk.pop();
                int l = stk.empty() ? -1 : stk.top();
                ret = max(ret, h * (r - l));
            }
            stk.push(i);
        }
        int r = stk.empty() ? -1 : stk.top();
        while (!stk.empty()) {
            int h = nums[stk.top()];
            stk.pop();
            int l = stk.empty() ? -1 : stk.top();
            ret = max(ret, h * (r - l));
        }
        return ret;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> preSum(m, vector<int>(n));
        for (int j = 0; j < n; ++j) {
            preSum[0][j] = matrix[0][j] == '0' ? 0 : 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                preSum[i][j] = matrix[i][j] == '0' ? 0 : preSum[i - 1][j] + 1;
            }
        }
        int ret = 0;
        for (int i = 0; i < m; ++i) {
            ret = max(ret, maxArea(preSum[i]));
        }
        return ret;
    }
};