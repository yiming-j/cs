class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        int p = 0;
        while (p <= j) {
            if (nums[p] == 0) {
                swap(nums[p], nums[i]);
                ++i;
                ++p;
            } else if (nums[p] == 1) {
                ++p;
            } else if (nums[p] == 2) {
                swap(nums[p], nums[j]);
                --j;
            }
        }
    }
};