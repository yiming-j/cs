class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) {
            return {};
        }
        vector<int> ret(n - k + 1);
        deque<int> dq;
        int p = 0;
        for (int i = 0; i < n; ++i) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (dq.front() <= i - k) {
                dq.pop_front();
            }
            if (i >= k - 1) {
                ret[p++] = nums[dq.front()];
            }
        }
        return ret;
    }
};