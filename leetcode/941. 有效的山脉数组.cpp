class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) {
            return false;
        }
        int i = 0;
        int n = A.size();
        if (A[i] > A[i + 1]) {
            return false;
        }
        while (i < n - 1 && A[i] < A[i + 1] ) {
            ++i;
        }
        if (i == n - 1) {
            return false;
        }
        while (i < n - 1 && A[i] > A[i + 1]) {
            ++i;
        }
        return i == n - 1;
    }
};