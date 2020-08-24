#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void *calloc(size_t nmemb, size_t size) {
    if (nmemb == 0 || size == 0) {
        return NULL;
    }

    size_t buffer_size = nmemb * size;
    if (buffer_size / size == nmemb) {
        void* p = malloc(buffer_size);
        if (p) {
            memset(p, 0, buffer_size);
            return p;
        }
    }
    return NULL;
}

int main() {
    void *p;
    p = calloc(0x1234, 1);
    assert(p != NULL);
    free(p);

    p = calloc(SIZE_MAX, 2);
    assert(p == NULL);
    free(p);
}