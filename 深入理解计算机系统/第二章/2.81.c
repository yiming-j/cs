#include <stdio.h>
#include <assert.h>

int funA(int k) {
    return -1 << k;
}

int funB(int k, int j) {
    return ~(-1 << k) << j;
}

int main(int argc, char* argv[]) {
  assert(funA(8) == 0xFFFFFF00);
  assert(funB(16, 8) == 0x00FFFF00);

  return 0;
}