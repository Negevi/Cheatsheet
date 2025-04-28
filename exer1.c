#include <stdio.h>

void main() {
    int d1,d2,d3;
    for(d1 = 1; d1 <= 6; d1++) {
        for(d2 = d1; d2 <= 6; d2++) {
            for(d3 = d2; d3 <= 6; d3++) {
                printf("%d %d %d \n", d1,d2,d3);
            }
        }
    }
}
