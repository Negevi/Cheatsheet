#include <stdio.h>

void main() {
    int n, fact;

    scanf("%d", &n);
    fact = n;
    for(n; n != 1; n--) {
        fact = (n - 1) * fact;
    }
    printf("Factorial = %d", fact);
}
