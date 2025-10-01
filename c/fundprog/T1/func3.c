#include <math.h>
#include <stdio.h>

double raizAproximada (double x, double erro_minimo) {
    double baixo = 1, alto = x, aprox = 0;
    if(x <= 1) {
        baixo = x; // muda os valores de comparação
        alto = 1;
    }
    
    while(fabs(x - (aprox * aprox)) > erro_minimo) {
        aprox = (baixo + alto) / 2;
            if(aprox * aprox > x)
                alto = aprox;
            else
                baixo = aprox;
        } // Uma func. bem simples!
        return aprox;
    }


void main() {
    double result;
    result = raizAproximada(113141, 0.005);
    printf("FINAL %f", result);
}