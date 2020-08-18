#include <stdio.h>

int funA(int x) {
    return !(~x);
}

int funB(int x) {
    return !x;
}

int funC(int x) {
    return !(~((x & 0xFF) | ~0xFF));
}

int funD(int x) {
    return !(x & ~0xFFFFFF);
}

int main() {
    printf("%d\n", funA(0xFFFFFFFF));
    printf("%d\n", funA(0x12345678));
    printf("%d\n", funB(0x00000000));
    printf("%d\n", funB(0x12345678));
    printf("%d\n", funC(0x123456FF));
    printf("%d\n", funC(0x12345678));
    printf("%d\n", funD(0x00345678));
    printf("%d\n", funD(0x12345678));
}