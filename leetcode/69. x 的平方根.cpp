class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }
        int lo = 1, hi = x / 2;
        while (lo + 1 < hi) {
            long long mi = lo + (hi - lo) / 2;
            if (mi * mi < x) {
                lo = mi;
            } else {
                hi = mi;
            }
        }
        if ((long long)hi * hi <= x) {
            return hi;
        }
        return lo;
    }
};