#include <stdio.h>

void main() {
    int n, i, range, found_num = 0;

    scanf("%d", &n);
    range = n;
    while(found_num == 0) {
        n++;
        found_num = 1;
        for(i = 2; i < range; i++) {
            if(n % i != 0) {
                found_num = 0;
            }
        }
    }
    printf("%d", n);
}
