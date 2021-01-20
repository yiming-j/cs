class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (i < 2 || nums[j] != nums[i - 2]) {
                nums[i] = nums[j];
                ++i;
            }
            ++j;
        }
        return i;
    }
};