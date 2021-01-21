class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0, hi = letters.size() - 1;
        while (lo + 1 < hi) {
            int mi = lo + (hi - lo) / 2;
            if (letters[mi] <= target) {
                lo = mi;
            } else {
                hi = mi;
            }
        }
        if (letters[lo] > target) {
            return letters[lo];
        } 
        if (letters[hi] > target) {
            return letters[hi];
        }
        return letters[0];
    }
};