#include <stdio.h>
#include <assert.h>

int funA(int x) {
    return (x << 4) + x;
}

int funB(int x) {
    return x - (x << 3);
}

int funC(int x) {
    return (x << 6) - (x << 2);
}

int funD(int x) {
    return (x << 4) - (x << 7);
}