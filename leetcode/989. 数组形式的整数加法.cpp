class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int idx = A.size() - 1;
        while (idx >= 0 && K) {
            A[idx] += K % 10;
            K = K / 10 + A[idx] / 10;
            A[idx] %= 10;
            --idx;
        }
        while (K) {
            A.insert(A.begin(), K % 10);
            K /= 10;
        }
        return A;
    }
};