#include <stdio.h>

void main() {
    int i, f;
    printf("Inicio - Fim")
    scanf("%d%d", &i, &f);

    if (f >= i) {
        printf("time = %d h", f - i);
    } else { // i > f
        printf("time = %d h", f - i + 24);
    }
}
