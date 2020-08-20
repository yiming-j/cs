#include <stdio.h>
#include <assert.h>

int mul3div4(int x) {
    int temp = x + (x << 1);
    int bias = (temp >> 31) & 3;
    return (temp + bias) >> 2;
}

int main() {
    int t = 0x12345678;
    assert(mul3div4(t) == (t * 3 / 4));
    return 0;
}