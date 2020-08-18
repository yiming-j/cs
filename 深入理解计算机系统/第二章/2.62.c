#include <stdio.h>

int int_shifts_are_arithmetic() {
    return !(~((int)0xFFFFFFFF >> 1));
}

int main() {
    printf("%d\n", int_shifts_are_arithmetic());
}