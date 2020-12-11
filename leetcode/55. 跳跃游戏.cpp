class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int end = 0;
        for (int i = 0; i < n; ++i) {
            if (i > end) {
                return false;
            }
            end = max(end, i + nums[i]);
            if (end >= n - 1) {
                return true;
            }
        }
        return false;
    }
};