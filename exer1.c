# define SIZE 9
# include <stdlib.h>

void main() {
    srand(4);
    int n, i, total = 0, med, menores = 0, maiores = 0;
    int v[SIZE];

    for(i = 0; i < SIZE; i++) {
        n = rand() % 59 + 20;
        printf("%d ", n);
        v[i] = n;
        total += n;
    }
    med = total / SIZE;

    for(i = 0; i < SIZE; i++) {
        if(v[i] > med)
            maiores++;
        else
            menores++;
    }
    printf("maiores %d, menores %d", maiores, menores);
}
