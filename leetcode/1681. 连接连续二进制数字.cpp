class Solution {   
public:
    int concatenatedBinary(int n) {
        constexpr int m = 1e9 + 7;
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            int len = 0;
            int x = i;
            while (x) {
                x >>= 1;
                ++len;
            }
            ans = ((ans << len) + i) % m;
        }
        return ans;
    }
};