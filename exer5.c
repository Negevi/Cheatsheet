#include <stdio.h>

void main() {
    int n, i, width, aux1, aux2, lines, f_down = 0;
    char symbol;

    scanf("%d %c", &n, &symbol);
    width = 2 * n + 1; // largura e numero total de linhas
    lines = width;
    aux1 = width / 2;
    aux2 = width - 2 * aux1;

    while(lines > 0) {
        for(i = 0; i < aux1; i++)
            printf(" ");
        for(i = 0; i < aux2; i++)
            printf("%c", symbol);
        printf("\n");

        if(aux1 <= 0)
            f_down = 1;
        if(f_down == 1) {
            aux1++;
            aux2 = width - 2 * aux1;
        } else {
            aux1--;
            aux2 = width - 2 * aux1;
        }
        lines--;
    }


}
