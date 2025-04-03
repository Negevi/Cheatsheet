#include <stdio.h><

void main() {
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);

    if (a > b) {
        if (a > c) {
        printf("A is greater");
        }
    } if (b > a) {
        if (b > c) {
        printf("B is greater");
        }
    } if (c > a) {
        if (c > b) {
        printf("C is greater");
        }
    }
    else {
        printf("Equal ints; No greater than number");
    }
}
