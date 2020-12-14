class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = nums.size() - 1;
        while (lo + 1 < hi) {
            int mi = lo + (hi - lo) / 2;
            int l = mi > 0 ? nums[mi - 1] : INT_MIN;
            int r = mi < n - 1 ? nums[mi + 1] : INT_MIN;
            if (nums[mi] > l && nums[mi] > r) {
                return mi;
            } else {
                if (nums[mi] > l) {
                    lo = mi;
                } else {
                    hi = mi;
                }
            }
        } 
        if (nums[lo] > nums[hi]) {
            return lo;
        }
        return hi;
    }
};