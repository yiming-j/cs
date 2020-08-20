#include <stdio.h> 

int lower_one_mask(int n) {
    unsigned w = sizeof(int) << 3;
    int mask = (unsigned)~0 >> (w - n);
    return mask;
}

int main() {
    printf("%#.8X\n", lower_one_mask(6));
    printf("%#.8X\n", lower_one_mask(17));
    printf("%#.8X\n", lower_one_mask(32));
}