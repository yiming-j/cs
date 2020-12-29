class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size();
        int ret = INT_MIN;
        for (int c1 = 0; c1 < n; ++c1) {
            vector<int> temp(m);
            for (int c2 = c1; c2 < n; ++c2) {
                for (int i = 0; i < m; ++i) {
                    temp[i] += matrix[i][c2];
                }
                vector<int> sum(m + 1);
                set<int> set;
                set.insert(0);
                for (int i = 0; i < m; ++i) {
                    sum[i + 1] = sum[i] + temp[i];
                    auto pos = set.lower_bound(sum[i + 1] - k);
                    if (pos != set.end()) {
                        ret = max(ret, sum[i + 1] - *pos);
                    }
                    set.insert(sum[i + 1]);
                }
            }
        }
        return ret;
    }
};