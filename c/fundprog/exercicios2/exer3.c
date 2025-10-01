#include <stdio.h>

void main() {
    int d, pts;

    scanf("%d", &d);

    if (d <= 800) {
        pts = 1;
    } else if (d <= 1600) {
        pts = 2;
    } else if (d <= 2000) {
        pts = 3;
    } else {
        printf("Invalid ");
    }
    printf("points: %d", pts);
}
