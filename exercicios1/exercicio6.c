#include <stdio.h>

void main() {
    float x, y;

    scanf("%f %f", &x, &y);

    if (x == 0.0) {
        if (y == 0.0) {
            printf("Origem");
        }
        else {
            printf("Eixo X");
        }
    }
    else if (y == 0.0) {
        printf("Eixo Y");
    }
    else if (x > 0.0) {
        // X positivo
        if (y > 0.0) {
            printf("Q1");
        } else {
            printf("Q4");
        }
    } else if (y > 0.0) {
        printf("Q2");
    } else {
        printf("Q3");
    }
}
