class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != i) {
                if (nums[nums[i]] == nums[i]) {
                    return nums[i];
                }
                swap(nums[i], nums[nums[i]]);
            } else {
                i++;
            }
        }
        return -1;
    }
};