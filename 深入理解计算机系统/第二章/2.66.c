#include <stdio.h>
#include <limits.h>

int leftmost_one(unsigned x) {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x & (~x >> 1 | INT_MIN);
}

int main() {
    printf("%#0.8X\n", leftmost_one(0xFF00));
    printf("%#0.8X\n", leftmost_one(0x6600));
}