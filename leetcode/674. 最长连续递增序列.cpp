class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count = 0;
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] <= nums[i - 1]) {
                count = 1;
            } else {
                ++count;
            }
            ret = max(ret, count);
        }
        return ret;
    }
};