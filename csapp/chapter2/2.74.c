#include <stdio.h>

int tsub_ok(int x, int y) {
    // INT_MIN取反直接溢出 -INT_MIN = INTMIN
    int z = -y;
    unsigned w = sizeof(int) << 3;
    int sign = (x ^ z) >> (w - 1);
    int overflow = ((x + z) ^ x) >> (w - 1);
    return !(z == y) && (sign || ~overflow);
}


int main() {
    printf("%d\n", tsub_ok(123456, 54321));
	printf("%d\n", tsub_ok(2147483647, -1));
	printf("%d\n", tsub_ok(-2147483648, 1));
    printf("%d\n", tsub_ok(1, -2147483648));
}