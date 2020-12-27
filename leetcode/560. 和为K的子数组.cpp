class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        map[0] = 1;
        int ret = 0;
        vector<int> sum(n + 1);
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
            if (map.count(sum[i + 1] - k)) {
                ret += map[sum[i + 1] - k];
            }
            ++map[sum[i + 1]];
        }
        return ret;
    }
};