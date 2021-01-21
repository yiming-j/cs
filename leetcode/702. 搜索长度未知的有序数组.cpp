/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int lo = 0, hi = 1;
        while (reader.get(hi) < target && reader.get(hi) != INT_MAX) {
            hi <<= 1;
        }
        lo = hi >> 1;
        while (lo + 1 < hi) {
            int mi = lo + (hi - lo) / 2;
            if (reader.get(mi) < target) {
                lo = mi;
            } else {
                hi = mi;
            }
        }
        if (reader.get(lo) == target) {
            return lo;
        } 
        if (reader.get(hi) == target) {
            return hi;
        }
        return -1;
    }
};