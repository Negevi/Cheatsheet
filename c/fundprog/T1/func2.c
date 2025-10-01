#include <stdio.h>

unsigned int fourcc(char c1, char c2, char c3, char c4) {
    return (c4 << 24 | c3 << 16 | c2 << 8 | c1); // legal 
}

void main() {
    printf("%d", fourcc('M', 'P', 'E', 'G'));
}