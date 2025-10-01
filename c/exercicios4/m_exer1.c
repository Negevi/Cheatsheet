#include <stdio.h>
#define N 4

void geraMatrizInca(int matriz[N][N], int size) {
    int valor = 1, offset = 0, i, j;
    while(valor <= N*N) {
        for(i = offset; i < N - offset; i++) {
            matriz[offset][i] = valor;
            valor++;
        }
        for(i = offset + 1; i < N - offset; i++) {
            matriz[i][N - 1 - offset] = valor;
            valor++;
        }
        for(i = N - 1 - offset; i > offset; i--) {
            matriz[N - 1 - offset][i] = valor;
            valor++;
        }
        for(i = N - 2 - offset; i > offset; i--) {
            matriz[i][offset] = valor;
            valor++;
        }
        offset++;
    }
}

void main() {
    int matriz[N][N] = {0};
    geraMatrizInca(matriz, N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
}


/* 32,31,30,20,10,11,12,22,21 */
