class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;
        int i = 0, j = 0, curr = 0;
        unordered_set<int> set;
        while (j < n) {
            while (j < n && !set.count(nums[j])) {
                curr += nums[j];
                set.insert(nums[j]);
                ++j;
            }
            if (curr > ret) {
                ret = curr;
            }
            if (j == n) {
                break;
            }
            while (nums[i] != nums[j]) {
                curr -= nums[i];
                set.erase(nums[i]);
                ++i;
            }
            curr -= nums[i];
            set.erase(nums[i]);
            ++i;
        }
        return ret;
    }
};