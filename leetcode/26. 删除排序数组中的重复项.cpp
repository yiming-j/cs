class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int i = 0, j = 0;
        int size = nums.size();
        while (j < size) {
            if (nums[j] != nums[i]) {
                nums[++i] = nums[j];
            }
            ++j;
        }
        return i + 1;
    }
};