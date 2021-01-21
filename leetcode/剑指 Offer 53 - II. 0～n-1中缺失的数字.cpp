class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo + 1 < hi) {
            int mi = lo + (hi - lo) / 2;
            if (nums[mi] == mi) {
                lo = mi;
            } else {
                hi = mi;
            }
        }
        if (nums[lo] != lo) {
            return lo;
        }
        if (nums[hi] != hi) {
            return hi;
        }
        return hi + 1;
    }
};