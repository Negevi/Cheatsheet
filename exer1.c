#include <stdio.h>

int arredonda(double x) {
    int intp = x, signal = 1;

    if(x < 0) {
        x = x * -1;
        intp = x;
        signal = -1;
    }

    if(x - intp >= 0.5)
        return (intp + 1) * signal;
    else
        return intp * signal;
}

void main() {
    double n;
    scanf("%lf", &n);
    printf("%d", arredonda(n));
}
