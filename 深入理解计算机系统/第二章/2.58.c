#include <stdio.h>

typedef unsigned char* byte_pointer;

int is_little_endian() {
    int x = 1;
    byte_pointer p = (byte_pointer) &x;
    return *p != 0;
}

int main() {
    int flag = is_little_endian();
    printf("%d\n", flag);
}