#include <stdio.h>
#define N 6

int check_param(int a, int b, int c) {
    int sum = a + b + c;
    if(sum >= 2)
        return 0;
    return 1;
}

void main() {
    int tab[N][N] = {{0,0,1,0,0,0},
                    {1,9,9,9,9,9},
                    {0,9,9,9,9,9},
                    {0,9,9,9,9,9},
                    {1,9,9,9,9,9},
                    {1,9,9,9,9,9}};

    for(int i = 1; i < N; i++) {
        for(int j = 1; j < N; j++) {
            tab[i][j] = check_param(tab[i][j - 1], tab[i - 1][j - 1], tab[i - 1][j]);
        }
    }

   for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d", tab[i][j]);
        }
        printf("\n");
    }
}
