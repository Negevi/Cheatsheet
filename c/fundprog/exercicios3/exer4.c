#include <stdio.h>
#define SMALL 2
#define LARGE 3
void main() {
    int m1[SMALL][LARGE] = {{2, 2, 2},
                            {1, 0, 1}};

    int m2[LARGE][SMALL] = {{2, 2},
                            {1, 0},
                            {2, 2}};

    int result[SMALL][SMALL];
    int n, offset, i, j;

    for(i = 0; i < SMALL; i++) {
        n = 0;
        for(j = 0; j < SMALL; j++) {
            n += m1[i + offset][j] * m2[i + offset][j];
            printf("N == %d\n", n);
        }
        offset++;
        result[i][j] = n;
    }

    for(int i = 0; i < SMALL; i++) {
        for(int j = 0; j < SMALL; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
