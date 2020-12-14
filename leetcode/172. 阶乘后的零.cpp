class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int divisor = 5;
        while (divisor <= n) {
            ans += n / divisor;
            divisor *= 5;
        }
        return ans;
    }
};