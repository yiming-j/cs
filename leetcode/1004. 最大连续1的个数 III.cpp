class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int count[2] = {0, 0};
        int i = 0, j = 0;
        int ret = 0;
        while (j < A.size()) {
            while (j < A.size()) {
                ++count[A[j]];
                ++j;
                if (count[1] + K >= j - i) {
                    ret = max(ret, j - i);
                } else {
                    break;
                }
            }
            --count[A[i]];
            ++i;
        }
        return ret;
    }
};