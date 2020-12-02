class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lo = 0, hi = arr.size() - 1;
        while (lo + 1 < hi) {
            int mi = lo + (hi - lo) / 2;
            if (arr[mi] < x) {
                lo = mi;
            } else {
                hi = mi;
            }
        }
        int p;
        if (abs(arr[lo] - x) <= abs(arr[hi] - x)) {
            p = lo;
        } else {
            p = hi;
        }
        int i = p, j = p;
        while (j - i + 1 < k) {
            if (i == 0) {
                ++j;
            } else if (j == arr.size() - 1) {
                --i;
            } else {
                int delta1 = abs(arr[i - 1] - x);
                int delta2 = abs(arr[j + 1] - x);
                if (delta1 <= delta2) {
                    --i;
                } else {
                    ++j;
                }
            }
        }
        return vector<int>(arr.begin() + i, arr.begin() + j + 1);
    }
};