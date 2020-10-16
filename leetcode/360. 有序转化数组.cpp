class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int size = nums.size();
        vector<int> ans(size);
        int l = 0, r = size - 1;
        int p = a > 0 ? size - 1 : 0;
        while (l <= r) {
            int l_value = a * nums[l] * nums[l] + b * nums[l] + c;
            int r_value = a * nums[r] * nums[r] + b * nums[r] + c;
            if (a > 0) {
                if (l_value > r_value) {
                    ans[p--] = l_value;
                    ++l;
                } else {
                    ans[p--] = r_value;
                    --r;
                }
            } else {
                if (l_value < r_value) {
                    ans[p++] = l_value;
                    ++l;
                } else {
                    ans[p++] = r_value;
                    --r;
                }
            }
        }
        return ans;
    }
};