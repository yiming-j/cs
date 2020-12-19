class Solution {
public:
    int minArray(vector<int>& numbers) {
        int lo = 0, hi = numbers.size() - 1;
        while (lo + 1 < hi) {
            int mi = lo + (hi - lo) / 2;
            if (numbers[mi] > numbers[hi]) {
                lo = mi;
            } else if (numbers[mi] < numbers[hi]) {
                hi = mi;
            } else {
                --hi;
            }
        }
        if (numbers[lo] < numbers[hi]) {
            return numbers[lo];
        }
        return numbers[hi];
    }
};