class Solution {
private:
    int check(vector<vector<int>> &matrix, int num) {
        int ret = 0;
        int n = matrix.size();
        int i = n - 1, j = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= num) {
                ret += i + 1;
                ++j;
            } else {
                --i;
            }
        }
        return ret;
    }
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n - 1][n - 1];
        while (lo + 1 < hi) {
            int mi = lo + (hi - lo) / 2;
            if (check(matrix, mi) < k) {
                lo = mi;
            } else {
                hi = mi;
            }
        }
        if (check(matrix, lo) >= k) {
            return lo;
        }
        return hi;
    }
};