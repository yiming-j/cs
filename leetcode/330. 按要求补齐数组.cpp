class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long r = 1;
        int i = 0;
        int ret = 0;
        while (r <= n) {
            if (i < nums.size() && nums[i] <= r) {
                r += nums[i++];
            } else {
                r <<= 1;
                ++ret;
            }
        }
        return ret;
    }
};