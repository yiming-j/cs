class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k && dq.front() <= i - k) {
                dq.pop_front();
            }
            ans[i] = nums[dq.front()];
        }
        return vector<int>(ans.begin() + k - 1, ans.end());
    }
};