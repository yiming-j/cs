// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n;
        while (lo + 1 < hi) {
            int mi = lo + (hi - lo) / 2;
            if (isBadVersion(mi)) {
                hi = mi;
            } else {
                lo = mi;
            }
        }
        if (isBadVersion(lo)) {
            return lo;
        }
        return hi;
    }
};