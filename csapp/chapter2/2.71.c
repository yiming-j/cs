#include <stdio.h>

// A. 取出负数被扩展为正数

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum) {
    return (int)word << ((3 - bytenum) << 3) >> 24;
}

int main(int argc, char const *argv[])
{
	packed_t word = 0x8008FF00;
	printf("%d\n", xbyte(word, 0));
	printf("%d\n", xbyte(word, 1));
	printf("%d\n", xbyte(word, 2));
	printf("%d\n", xbyte(word, 3));
	return 0;
}