#include <stdio.h> 

unsigned srl(unsigned x, int k) {
    unsigned xsra = (int) x >> k;
    int shift_val = sizeof(int) * 8 - k;
    unsigned mask = (1 << shift_val) - 1;
    return xsra & mask;
} 

int sra(int x, int k) {
    int xsrl = (unsigned) x >> k;
    int shift_val = sizeof(int) * 8 - k - 1;
    unsigned mask = ~(((1 << shift_val) & xsrl) - 1);
    return xsrl | mask;
}

int main() {
    printf("%#0.8X\n", srl(0x80000000, 8));
    printf("%#0.8X\n", sra(0x80000000, 8));
}