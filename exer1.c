#include <stdio.h>
#define I 2
#define J 3

void main() {
    int max = 0, compare;
    int campo [I][J] = {{81, 28, 240, 10},
                        {40, 10, 100, 240},
                        {20, 180, 110, 35}};
    for(int i = 0; i < I; i++) {
    compare = 0;
        for(int j = 0; j < J; j++) {
            compare += campo[i][j];
        }
        if(compare > max)
            max = compare;
    }

    for(int j = 0; j <= J; j++) {
    compare = 0;
        for(int i = 0; i <= I; i++) {
            compare += campo[i][j];
        }
        if(compare > max)
            max = compare;
    }

    printf("max %d", max);
}
