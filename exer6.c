#include <stdio.h>

unsigned int inverteNum(unsigned int n) {
    unsigned int inverted = 0;

    while(n > 0) {
        inverted = inverted * 10 + n % 10;
        n = n / 10;
    }
    return inverted;
}

void main() {
        printf("%u", inverteNum(1234));
}
