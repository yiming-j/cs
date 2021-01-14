class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, j = 0;
        int sum = 0;
        int ret = INT_MAX;
        while (j < nums.size()) {
            while (j < nums.size() && sum < s) {
                sum += nums[j++];
            }
            while (i < j && sum >= s) {
                ret = min(ret, j - i);
                sum -= nums[i++];
            }
        }
        return ret == INT_MAX ? 0 : ret;
    }
};