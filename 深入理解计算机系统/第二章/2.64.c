#include <stdio.h>

int any_add_one(unsigned x) {
    return !!(x & 0x55555555);
}

int main() {
    printf("%d\n", any_add_one(1010));
    printf("%d\n", any_add_one(512));
}