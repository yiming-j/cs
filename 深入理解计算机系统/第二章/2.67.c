#include <stdio.h>

// A. 左/右移长度不能大于或等于字长
// (C11, 6.5.7p3) "If the value of the right operand is negative or is greater than or equal to 
// the width of the promoted left operand, the behavior is undefined"

int bad_int_size_is_32() {
    int set_msb = 1 << 31;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}

int main() {
    printf("%d\n", bad_int_size_is_32());
}