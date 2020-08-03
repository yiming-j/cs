/**
 * 1-11
 * 测试边界条件：没有单词、一串空行等等
 */

#include <stdio.h>
#define IN 1
#define OUT 0

main() {
    int c, state;
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c =='\n') {
            if (state == IN) {
                state = OUT;
                putchar('\n');
            }
        } else {
            state = IN;
            putchar(c);
        }
    }
}

