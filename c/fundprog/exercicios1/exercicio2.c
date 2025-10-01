#include <stdio.h>

void main() {
    int n;

    scanf("%d", &n);

    int c = n / 100;
    int d = n % 100 / 10;
    int u = n % 10;

    printf("%d", u*100+d*10+c);
}
