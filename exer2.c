#include <stdio.h>

double casasDecimais(double n) {
    int intp = n;
    return (n - intp);
}

void main() {
    printf("%lf", casasDecimais(1.54367));
}
