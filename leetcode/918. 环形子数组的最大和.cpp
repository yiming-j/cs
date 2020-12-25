class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        if (n == 0) {
            return 0;
        }
        int maxCurr = 0, minCurr = 0;
        int maxValue = INT_MIN, minValue = INT_MAX;
        for (int i = 0; i < n; ++i) {
            maxCurr = max(maxCurr + A[i], A[i]);
            minCurr = min(minCurr + A[i], A[i]);
            maxValue = max(maxValue, maxCurr);
            minValue = min(minValue, minCurr);
        }
        int sum = accumulate(A.begin(), A.end(), 0);
        if (sum == minValue) {
            return maxValue;
        }
        return max(maxValue, sum - minValue);
    }
};