class Solution {
private:
    int findFirst(vector<int>& nums, int target) {
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
    
    int findLast(vector<int>& nums, int target) {
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
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        if (first == -1) {
            return 0;
        }
        return last - first + 1;
    }
};