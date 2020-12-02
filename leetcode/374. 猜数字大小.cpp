/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1, hi = n;
        while (lo + 1 < hi) {
            int mi = lo + (hi - lo) / 2;
            int cond = guess(mi);
            if (cond == 0) {
                return mi;
            } else if (cond == 1) {
                lo = mi;
            } else {
                hi = mi;
            }
        }
        if (guess(lo) == 0) {
            return lo;
        }
        return hi;
    }
};