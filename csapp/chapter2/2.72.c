#include <stdio.h>

// A. maxbytes被转换为无符号数运算，结果总是大于0

void copy_int(int val, void *buf, int maxbytes) {
    if (maxbytes - (int)sizeof(val) >= 0) {
        memcpy(buf, (void*) &val, sizeof(val));
    }
}