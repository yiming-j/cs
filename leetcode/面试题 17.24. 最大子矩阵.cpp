class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ret(4);
        vector<int> nums(n);
        int maxValue = INT_MIN;
        for (int r1 = 0; r1 < m; ++r1) {
            for (int j = 0; j < n; ++j) {
                nums[j] = 0;
            }
            for (int r2 = r1; r2 < m; ++r2) {
                for (int j = 0; j < n; ++j) {
                    nums[j] += matrix[r2][j];
                }
                int c1 = 0, c2 = 0;
                int curr = 0;
                for (int j = 0; j < n; ++j) {
                    if (curr + nums[j] > nums[j]) {
                        curr += nums[j];
                        ++c2;
                    } else {
                        curr = nums[j];
                        c1 = j;
                        c2 = j;
                    }
                    if (curr > maxValue) {
                        maxValue = curr;
                        ret[0] = r1;
                        ret[1] = c1;
                        ret[2] = r2;
                        ret[3] = c2;
                    }
                }
            }
        }
        return ret;
    }
};