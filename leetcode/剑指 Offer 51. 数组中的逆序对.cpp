class Solution {
private:
    int divide(vector<int>& nums, int lo, int hi) {
        if (lo == hi) {
            return 0;
        }
        int mi = lo + (hi - lo) / 2;
        int left = divide(nums, lo, mi);
        int right = divide(nums, mi + 1, hi);
        int ret = left + right;
        vector<int> temp(hi - lo + 1);
        int i = lo, j = mi + 1, k = 0;
        while (i <= mi && j <= hi) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                ret += mi - i + 1;
                temp[k++] = nums[j++];
            }
        }
        while (i <= mi) {
            temp[k++] = nums[i++];
        }
        while (j <= hi) {
            temp[k++] = nums[j++];
        }
        for (int i = 0; i < k; ++i) {
            nums[lo + i] = temp[i];
        }
        return ret;
    }
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        return divide(nums, 0, nums.size() - 1);
    }
};