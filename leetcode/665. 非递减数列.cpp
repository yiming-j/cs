class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() <= 1) {
            return true;
        }
        int flag = nums[0] <= nums[1];
        for (int i = 1; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                if (flag) {
                    if (nums[i + 1] >= nums[i - 1]) {
                        nums[i] = nums[i + 1];
                    } else {
                        nums[i + 1] = nums[i];
                    }
                    --flag;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

