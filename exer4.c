int ehParFoolano(unsigned int n1, unsigned int n2) {
    int inverted;
    while(n2 > 0) {
        // i == pot
        inverted = inverted * 10 + (n2 % 10);
        n2 /= 10;
    }

    if(n1 == n2)
        return 1;
    return 0;
}

void main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    if(ehParFoolano(n1, n2))
        printf("foolano");
    else
        printf("boolano");
}
