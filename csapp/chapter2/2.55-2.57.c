#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void* x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void show_short(short x) {
    show_bytes((byte_pointer) &x, sizeof(short));
}

void show_long(long x) {
    show_bytes((byte_pointer) &x, sizeof(long));
}

void show_double(double x) {
    show_bytes((byte_pointer) &x, sizeof(double));
}

// 12345 0x00003039 12345.0 0x4640e400
int main() {
    int x = 12345;
    float f = 12345.0;
    int *p = &x;
    show_int(x);
    // 39 30 00 00
    show_float(f);
    // 00 e4 40 46
    show_pointer(p);
    // fc 38 2e e4 fe 7f 00 00 不固定
    show_short(x);
    // 39 30
    show_long(x);
    // 39 30 00 00 00 00 00 00
    show_double(f);
    // 00 00 00 00 80 1c c8 40
    // 小端机器
}

