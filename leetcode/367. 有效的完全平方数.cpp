class Solution {
public:
    bool isPerfectSquare(int num) {
        int lo = 1, hi = num / 2;
        while (lo + 1 < hi) {
            int mi = lo + (hi - lo) / 2;
            if ((long long)mi * mi < num) {
                lo = mi;
            } else {
                hi = mi;
            }
        }
        if ((long long)lo * lo == num || (long long)hi * hi == num) {
            return true;
        }
        return false;
    }
};