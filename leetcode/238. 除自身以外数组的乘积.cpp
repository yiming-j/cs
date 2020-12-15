class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int l = 1, r = 1;
        for (int i = 0, j = n - 1; i < n; ++i, --j) {
            ans[i] *= l;
            ans[j] *= r;
            l *= nums[i];
            r *= nums[j];
        }
        return ans;
    }
};