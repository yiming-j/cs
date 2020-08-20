#include <stdio.h>
#include <assert.h>

int threeforths(int x) {
    int l = x & ~3;
    int r = x & 3;
    int l_temp = l >> 2;
    int r_temp = r + (r << 1);
    int r_bias = (x >> 31) & 3;
    return l_temp + (l_temp << 1) + ((r_temp + r_bias) >> 2);
}

int main() {
    assert(threeforths(8) == 6);
    assert(threeforths(9) == 6);
    assert(threeforths(10) == 7);
    assert(threeforths(11) == 8);
    assert(threeforths(12) == 9);

    assert(threeforths(-8) == -6);
    assert(threeforths(-9) == -6);
    assert(threeforths(-10) == -7);
    assert(threeforths(-11) == -8);
    assert(threeforths(-12) == -9);
}