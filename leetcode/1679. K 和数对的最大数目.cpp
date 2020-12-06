class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums.size() - 1;
        int ans = 0;
        while (lo < hi) {
            int curr = nums[lo] + nums[hi];
            if (curr == k) {
                ++ans;
                ++lo;
                --hi;
            } else if (curr < k) {
                ++lo;
            } else {
                --hi;
            }
        }
        return ans;
    }
};