class Solution {
private:
    int quickSelect(vector<int> &nums, int lo, int hi, int k) {
        if (lo == hi) {
            return nums[lo];
        }
        int pivot = nums[lo + (hi - lo) / 2];
        int left = lo, right = hi;
        while (left <= right) {
            while (left <= right && nums[left] > pivot) {
                ++left;
            }
            while (left <= right && nums[right] < pivot) {
                --right;
            }
            if (left <= right) {
                swap(nums[left], nums[right]);
                ++left;
                --right;
            }
        }
        if (k - 1 <= right) {
            return quickSelect(nums, lo, right, k);
        } else if (k - 1 >= left) {
            return quickSelect(nums, left, hi, k);
        }
        return nums[right + 1];
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};