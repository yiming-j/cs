class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int ret = 0;
        for (const auto &num : nums) {
            if (num == 1) {
                ++count;
                ret = max(ret, count);
            } else {
                count = 0;
            }
        }
        return ret;
    }
};