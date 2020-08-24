#include <stdio.h>
#include <assert.h>
#include <inttypes.h>

int signed_high_prod(int x, int y) {
    int64_t mul = (int64_t) x * y;
    return mul >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
    unsigned sig_x = x >> 31;
    unsigned sig_y = y >> 31;
    return signed_high_prod(x, y) + x * sig_y + y * sig_x;
}

unsigned another_unsigned_high_prod(unsigned x, unsigned y) {
  uint64_t mul = (uint64_t) x * y;
  return mul >> 32;
}

int main() {
    unsigned x = 0x12345678;
    unsigned y = 0xFFFFFFFF;

    assert(another_unsigned_high_prod(x, y) == unsigned_high_prod(x, y));
}