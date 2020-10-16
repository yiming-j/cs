class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int len = A.size();
        vector<int> ans(len);
        int i = 0, j = len - 1;
        int p = len - 1;
        while (i <= j) {
            if (-A[i] >= A[j]) {
                ans[p] = A[i] * A[i];
                ++i;
            } else {
                ans[p] = A[j] * A[j];
                --j;
            }
            --p;
        }
        return ans;
    }
};