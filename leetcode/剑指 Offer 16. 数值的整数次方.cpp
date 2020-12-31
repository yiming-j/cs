class Solution {
private:
    double myPow(double x, long long n) {
        if (n == 1) {
            return x;
        }
        return n % 2 ? x * myPow(x * x, n / 2) : myPow(x * x, n / 2);
    }
public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        long long N = n;
        return N > 0 ? myPow(x, N) : 1 / myPow(x, -N);
    }
};