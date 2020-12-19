class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            while (lo < hi && nums[lo] % 2 == 1) {
                ++lo;
            }
            while (lo < hi && nums[hi] % 2 == 0) {
                --hi;
            }
            if (lo < hi) {
                swap(nums[lo], nums[hi]);
                ++lo;
                --hi;
            }
        }
        return nums;
    }
};