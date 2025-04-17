#include <stdio.h>

void main() {
    int n = 1, i, last_n, counter = 1;

    scanf("%d", &n);
    while(n > 0) { // check if code should keep running
        last_n = n;
        scanf("%d", &n);
        for(i = 2; last_n < n; i++) { // while cresc
            if(i > counter)
                counter = i;
            last_n = n;
            scanf("%d", &n);
        }
    }
    printf("%d", counter);
}
