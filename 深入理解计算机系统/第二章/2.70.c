#include <stdio.h>
#include <limits.h>

int fits_bits(int x, int n) {
    unsigned w = sizeof(int) << 3;
    int y = x << (w - n) >> (w - n);
    return y == x;
}

int main() {
	printf("%d\n", fits_bits(-32768, 16));
	printf("%d\n", fits_bits(32767, 16));
	printf("%d\n", fits_bits(INT_MAX, 32));
	printf("%d\n", fits_bits(INT_MIN, 32));
	printf("%d\n", fits_bits(0, 16));
	printf("%d\n", fits_bits(0, 32));
	printf("%d\n", fits_bits(32768, 16));
	printf("%d\n", fits_bits(-32769, 16));
	printf("%d\n", fits_bits(INT_MIN, 31));
	printf("%d\n", fits_bits(INT_MAX, 31));
}