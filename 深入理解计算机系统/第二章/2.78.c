#include <stdio.h>
#include <assert.h>

int divide_power2(int x, int k) {
    int sign_mask = x >> 31;
    int bias = ((1 << k) - 1) & sign_mask;
    return (x + bias) >> k;
}

int main() {
    int x = 0x80000007;
    assert(divide_power2(x, 1) == x / 2);
    assert(divide_power2(x, 2) == x / 4);    
}