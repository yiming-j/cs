class Solution {
private:
    int div(long long a, long long b) {
        if (a < b) {
            return 0;
        }
        long long temp = b;
        int count = 1;
        while (temp + temp <= a) {
            temp += temp;
            count += count;
        }
        return count + div(a - temp, b);
    }
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) {
            return 0;
        }
        if (divisor == 1) {
            return dividend;
        }
        if (divisor == -1) {
            if (dividend == INT_MIN) {
                return INT_MAX;
            }
            return -dividend;
        }
        long long a = dividend;
        long long b = divisor;
        int sign = 1;
        if ((a > 0 && b < 0) || (a < 0 && b > 0)) {
            sign = -1;
        }
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        return sign * div(a, b);
    }
};