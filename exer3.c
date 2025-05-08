#include <stdio.h>

int proxFibonacci (int n) {
    int fibo1 = 0, fibo2 = 1;

    while(fibo1 + fibo2 < n) {
        fibo1 = fibo2;
        fibo2 = fibo1 + fibo2;
    }
    return fibo1 + fibo2;
}

void main() {
    printf("%d", proxFibonacci(15));
}
