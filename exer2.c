#include <stdio.h>

void main() {
    int i, n = 0, past_n, decres_flag = 1, cresc_flag = 1;
    scanf("%d", &i);
    printf("Numero? (%d)\n", i);
    scanf("%d", &past_n);
    for(i -= 1; i > 0; i--) {
        printf("Numero? (%d)\n", i);
        scanf("%d", &n);
        if(n > past_n) {
            decres_flag = 0;
        } else if(n < past_n) {
            cresc_flag = 0;
        } else {
            cresc_flag = 0;
            decres_flag = 0;
        }
    }
    if(cresc_flag == 1)
        printf("Crescente");
    else if(decres_flag == 1)
        printf("Decrescente");
    else
        printf("nada");
}
