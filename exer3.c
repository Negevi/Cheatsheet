#include <stdio.h>

void main() {
    int n1, n2, q = 0;

    scanf("%d %d", &n1, &n2);

    while(n1 - n2 >= 0) {
        n1 = n1 - n2;
        q++;
    }
    printf("Quociente: %d, Resto: %d", q, n1);
}
