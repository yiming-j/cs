class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i = 2; i < size; ++i) {
            if (nums[i] < 0) {
                continue;
            }
            if (i < size - 1 && nums[i] == nums[i + 1]) {
                continue;
            }
            if (nums[i - 2] + nums[i - 1] + nums[i] < 0) {
                continue;
            }
            if (nums[0] + nums[1] + nums[i] > 0) {
                break;
            }
            int target = -nums[i];
            int left = 0, right = i - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    ans.push_back({nums[left], nums[right], -target});
                    ++left;
                    --right;
                    while (left < right && nums[left] == nums[left - 1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        --right;
                    }
                } else if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return ans;
    }
};