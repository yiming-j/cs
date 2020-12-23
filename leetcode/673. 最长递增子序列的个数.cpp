class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> len(n, 1);
        vector<int> count(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] <= nums[j]) {
                    continue;
                }
                if (len[i] < len[j] + 1) {
                    len[i] = len[j] + 1;
                    count[i] = count[j];
                } else if (len[i] == len[j] + 1) {
                    count[i] += count[j];
                }
            }
        }
        int maxLen = *max_element(len.begin(), len.end());
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if (len[i] == maxLen) {
                ret += count[i];
            }
        }
        return ret;
    }
};