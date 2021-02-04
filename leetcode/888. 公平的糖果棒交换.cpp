class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        int delta = (sumB - sumA) / 2;
        unordered_set<int> setA(A.begin(), A.end());
        for (const auto &b : B) {
            if (setA.count(b - delta)) {
                return {b - delta, b};
            }
        }
        return {};
    }
};