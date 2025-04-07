#include <stdio.h>

void main() {
    float a_price, g_price,
          a_kliter, g_kliter;

    printf("Alcool / aliter");
    scanf("%f %f", &a_price, &a_kliter);

    printf("Gas / gliter");
    scanf("%f %f", &g_price, &g_kliter);


    if (a_price * a_kliter >= g_price * g_kliter) {
        printf("Gas is cheaper (or equal) !");
    }
    else {
        printf("Alc. is cheaper!");
    }


}
