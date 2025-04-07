#include <stdio.h>

void main() {
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    if (n1 > n2 && n1 >n3) {
        if (n2 > n3) {
            printf("ordem crescente: %d %d %d", n1, n2, n3);
        }
        else {
            printf("ordem crescente: %d %d %d", n1, n3, n2);
        }
    } else if (n2 > n1 && n2 >n3) {
        if (n1 > n3) {
            printf("ordem crescente: %d %d %d", n2, n3, n1);
        }
        else {
            printf("ordem crescente: %d %d %d", n2, n1, n3);
        }
    } else if (n3 > n1 && n3 > n2) {
        if (n1 > n2) {
            printf("ordem crescente: %d %d %d", n3, n1, n2);
        }
        else {
            printf("ordem crescente: %d %d %d", n3, n2, n1);
        }
    }
}
