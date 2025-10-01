#include <stdio.h>

void main() {
    int l1, l2, l3, cond;
    scanf("%d %d %d", &l1, &l2, &l3);

    if (l1 < l2 + l3 && l2 < l3 + l1 && l3 < l1 + l2) {
        if (l1 == l2 == l3) {
            printf("Equilat");
        } else if (l1 == l2 || l1 == l3 || l2 == l3) {
            printf("Isoc");
        } else {
            printf("Escaleno");
        }
    } else {
        printf("Invalido");
    }
}
