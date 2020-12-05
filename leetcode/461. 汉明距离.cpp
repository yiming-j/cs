class Solution {
public:
    int hammingDistance(int x, int y) {
        uint32_t z = x ^ y;
        int ans = 0;
        while (z != 0) {
            ans += z & 0x1;
            z >>= 1;
        }
        return ans;
    }
};