class Solution {
private:
    int findFirst(vector<int> &nums, int target) {
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
    
    int findLast(vector<int> &nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo + 1 < hi) {
            int mi = lo + (hi - lo) / 2;
            if (nums[mi] <= target) {
                lo = mi;
            } else {
                hi = mi;
            }
        }
        if (nums[hi] == target) {
            return hi;
        }
        if (nums[lo] == target) {
            return lo;
        }
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }
        return {findFirst(nums, target), findLast(nums, target)};
    }
};