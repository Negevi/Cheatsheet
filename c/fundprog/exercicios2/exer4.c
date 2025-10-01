#include <stdio.h>

void main() {
    int money,
        c1, c2, c5, c10, c20, c50, c100;
    scanf("%d", &money);

    c100 = money / 100;
    c50 = money % 100 / 50;
    c20 = money % 50 / 20;
    c10 = money % 20 / 10;
    c5 = money % 10 / 5;
    c2 = money % 5 / 2;
    c1 = money % 2;

    printf("%d de 100, %d de 50, %d de 20, %d de 10, %d de 5, %d de 2 e %d de 1", c100, c50, c20, c10, c5, c2, c1);
}
