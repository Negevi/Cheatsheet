#include <stdio.h>

void main() {
    int d, m, y,
    pd, pm, py, years;

    printf("Idade (dd/mm/yyyy) : ");
    scanf("%d/%d/%d", &d, &m, &y);
    printf("Hoje (dd/mm/yyyy) : ");
    scanf("%d/%d/%d", &pd, &pm, &py);

    years = py - y;

    if (pd < d && pm < m) {
        years = years - 1;
    }

    printf("%d", years);

}
