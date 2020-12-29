class Solution {
private:
    int rob(vector<int>& nums, int lo, int hi) {
        if (lo == hi) {
            return nums[lo];
        }
        int first = nums[lo], second = max(nums[lo], nums[lo + 1]);
        for (int i = lo + 2; i <= hi; ++i) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        return max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
    }
};