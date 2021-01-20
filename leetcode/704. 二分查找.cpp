class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo + 1 < hi) {
            int mi = lo + (hi - lo) / 2;
            if (nums[mi] < target) {
                lo = mi;
            } else {
                hi = mi;
            }
        }
        if (nums[lo] == target) {
            return lo;
        }
        if (nums[hi] == target) {
            return hi;
        }
        return -1;
    }
};