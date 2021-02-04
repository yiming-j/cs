class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ret = 1;
        deque<int> mindq, maxdq;
        int i = 0, j = 0;
        while (j < nums.size()) {
            if ((mindq.empty() && maxdq.empty()) || (nums[j] - nums[mindq.front()] <= limit && nums[maxdq.front()] - nums[j] <= limit)) {
                ret = max(ret, j - i + 1);
                while (!mindq.empty() && nums[mindq.back()] > nums[j]) {
                    mindq.pop_back();
                }
                mindq.push_back(j);
                while (!maxdq.empty() && nums[maxdq.back()] < nums[j]) {
                    maxdq.pop_back();
                }
                maxdq.push_back(j);
                ++j;
            } else {
                ++i;
                if (!mindq.empty() && mindq.front() < i) {
                    mindq.pop_front();
                }
                if (!maxdq.empty() && maxdq.front() < i) {
                    maxdq.pop_front();
                }
            }
        }
        return ret;
    }
};