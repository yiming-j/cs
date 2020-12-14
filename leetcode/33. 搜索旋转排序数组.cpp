class Solution {
private:
    int searchMin(vector<int>& nums, int lo, int hi) {
        int n = nums.size();
        while (lo + 1 < hi) {
            int mi = lo + (hi - lo) / 2;
            if (nums[mi] >= nums[n - 1]) {
                lo = mi;
            } else {
                hi = mi;
            }
        }
        if (nums[lo] < nums[hi]) {
            return lo;
        }
        return hi;
    }
    
    int searchTarget(vector<int>& nums, int lo, int hi, int target) {
        while (lo + 1 < hi) {
            int mi = lo + (hi - lo) / 2;
            if (nums[mi] == target) {
                return mi;
            }
            if (nums[mi] < target) {
                lo = mi;
            } else {
                hi = mi;
            }
        }
        if (nums[lo] == target) {
            return lo;
        } else if (nums[hi] == target) {
            return hi;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int minIdx = searchMin(nums, lo, hi);
        if (minIdx == 0) {
            return searchTarget(nums, lo, hi, target);
        }
        if (target >= nums[0]) {
            return searchTarget(nums, lo, minIdx - 1, target);
        }
        return searchTarget(nums, minIdx, hi, target);
    }
};