class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int ans = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] != ans) {
                --count;
                if (count == 0) {
                    ans = nums[i];
                    count = 1;
                }
            } else {
                ++count;
            }
        }
        return ans;
    }
};