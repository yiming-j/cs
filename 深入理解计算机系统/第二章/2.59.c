#include <stdio.h>

int foo(int x, int y) {
    return (x & 0xFF) | (y & ~0xFF);
}
int main() {
    int x = 0x89ABCDEF;
    int y = 0x76543210;
    printf("0x%.8X\n", foo(x, y));
}

