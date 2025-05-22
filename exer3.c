#include <stdlib.h>
#include <stdio.h>
#define N 10

void main() {
    srand(time(NULL));
    int i, v[N];

    printf("primeiro vec: ");
    for(i = 0; i < N; i++) {
        v[i] = rand() % 99 + 1; // 1 a 100
        printf("%d ", v[i]);
    }

    printf("invertido: ");
    for(i = 0; i < N; i++) {
        v[i] = v[N - i - 1];
        printf("%d ", v[i]);
    }
}
