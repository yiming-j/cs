class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> stk;
        int l = INT_MAX, r = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            while (!stk.empty() && nums[i] < nums[stk.top()]) {
                l = min(l, stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            stk.pop();
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            while (!stk.empty() && nums[i] > nums[stk.top()]) {
                r = max(r, stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        return r > l ? r - l + 1 : 0;
    }
};