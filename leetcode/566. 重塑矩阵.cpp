class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.size() == 0 || nums[0].size() == 0) {
            return {};
        }
        int m = nums.size(), n = nums[0].size();
        if (m * n != r * c) {
            return nums;
        }
        vector<vector<int>> ret(r, vector<int>(c));
        int idx = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ret[idx / c][idx % c] = nums[i][j];
                ++idx;
            }
        }
        return ret;
    }
};