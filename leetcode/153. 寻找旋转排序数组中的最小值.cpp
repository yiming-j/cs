class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo + 1 < hi) {
            int mi = lo + (hi - lo) / 2;
            if (nums[mi] < nums[hi]) {
                hi = mi;
            } else if (nums[mi] > nums[hi]) {
                lo = mi;
            } else {
                --hi;
            }
        }
        if (nums[lo] < nums[hi]) {
            return nums[lo];
        }
        return nums[hi];
    }
};