#include <stdlib.h>
#include <stdio.h>

void main() {
    int i, n, range, sum = 0, part = 0;
    printf("RANGE: ");
    scanf("%d", &range);

    int vec[100];

    printf("sizes: ");
    for(i = 0; i < range; i++) {
        scanf("%d", &vec[i]);
        sum += vec[i];
    }

    for(i = 0; part <= (sum / 2); i++) {
        part += vec[i];
    }
    printf("Int: %d", vec[i]);
}
