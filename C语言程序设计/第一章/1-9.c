#include <stdio.h>
#define NOBLANK 'a'

main() {
    int curr, prev;
    prev = NOBLANK;
    while ((curr = getchar()) != EOF) {
        if (curr != ' ') {
            putchar(curr);
        } else if (curr == ' ' && prev != ' ') {
            putchar(' ');
        }
        prev = curr;
    }
}