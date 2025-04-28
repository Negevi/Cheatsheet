#include <stdio.h>

void main() {
    int n, i, tested_n = 2,
        prime, counter = 0, soma = 0; // <- variaveis acesorias
    scanf("%d", &n);

    while(n != counter) {
        prime = 1; // assume n is prime
        for(i = 2; i < tested_n; i++) {
        // printf("in loop %d", tested_n);
            if(tested_n % i == 0) {
                prime = 0;
                // printf("not prime");
            }
        }
        if(prime == 1) { // if prime
            soma += tested_n;
            counter++;
        }
        tested_n++;
    }
    printf("%d", soma);
}
