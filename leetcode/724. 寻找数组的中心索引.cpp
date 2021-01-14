class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> r(n);
        for (int i = n - 2; i >= 0; --i) {
            r[i] = r[i + 1] + nums[i + 1];
        }
        int l = 0;
        for (int i = 0; i < n; ++i) {
            if (l == r[i]) {
                return i;
            }
            l += nums[i];
        }
        return -1;
    }
};