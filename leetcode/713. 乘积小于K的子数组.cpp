class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int ret = 0;
        int prod = 1;
        while (j < nums.size()) {
            prod *= nums[j++];
            while (i < j && prod >= k) {
                prod /= nums[i++];
            }
            ret += j - i;
        }
        return ret;
    }
};