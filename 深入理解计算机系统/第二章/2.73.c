#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y) {
	unsigned w = sizeof(int) << 3;
    int sign = (x ^ y) >> (w - 1);
    int overflow = ((x + y) ^ x) >> (w - 1);
	int neg = x >> (w - 1);
    return (sign & (x + y)) |
            (~sign & ((~overflow & (x + y)) | 
                    (overflow & ((neg & INT_MIN) | (~neg & INT_MAX)))));
}

int main() {
	printf("%d\n", saturating_add(123456, 123456));
    printf("%d\n", saturating_add(123456, -123456));
    printf("%d\n", saturating_add(-123456, -123456));
	printf("%d\n", saturating_add(2147483647, 1));
	printf("%d\n", saturating_add(-2147483648, -1));
}

