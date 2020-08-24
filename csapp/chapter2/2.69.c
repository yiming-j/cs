#include <stdio.h>

unsigned rotate_left(unsigned x, int n) {
    unsigned xleft = x & ~((unsigned)~0 >> n);
    return (x << n) | (xleft >> ((sizeof(int) << 3) - n));
}

int main() {
    printf("%#.8X\n", rotate_left(0x12345678, 4));
    printf("%#.8X\n", rotate_left(0x12345678, 0));
    printf("%#.8X\n", rotate_left(0x12345678, 20));
}