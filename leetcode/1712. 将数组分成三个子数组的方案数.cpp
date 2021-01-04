class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int m = 1e9 + 7;
        int n = nums.size();
        vector<int> sum(n + 1);
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
        } 
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            auto begin = lower_bound(sum.begin() + 2 + i, sum.end() - 1, 2 * sum[i + 1]);
            auto end = upper_bound(sum.begin() + 2 + i, sum.end() - 1, (sum[n] + sum[i + 1]) / 2);
            --end;
            if (end < begin) {
                continue;
            }
            ret = (ret + end - begin + 1) % m;
        }
        return ret;
    }
};