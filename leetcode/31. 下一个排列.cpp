class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0) {
            if (nums[i] >= nums[i + 1]) {
                --i;
            } else {
                break;
            }
        }
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = i;
        while (j < nums.size() - 1) {
            if (nums[j + 1] > nums[i]) {
                ++j;
            } else {
                break;
            }
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};
