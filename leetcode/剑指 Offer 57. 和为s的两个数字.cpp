class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            if (nums[lo] + nums[hi] == target) {
                return {nums[lo], nums[hi]};
            } else if (nums[lo] + nums[hi] < target) {
                ++lo;
            } else {
                --hi;
            }
        }
        return {};
    }
};