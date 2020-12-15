class Solution {
private:
    double myPow(double x, long long N) {
        if (N == 0) {
            return 1;
        }
        return N % 2 == 0 ? myPow(x * x, N / 2) : x * myPow(x * x, N / 2);
    }
public:
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? myPow(x, N) : 1 / myPow(x, -N);
    }
};