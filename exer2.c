void remove_extremos(int *n, int *pri, int *ult) {
    int tn, pot = 1;

    tn = *n;
    while(tn >= 10) {
        tn = tn/10;
        pot *= 10;
    }

    *pri = *n / pot;
    *ult = *n % 10;
    *n = *n % pot;
    *n = *n /10;
}

void main() {
    int n = 55555, pri, ult, palind = 1;

    while(n > 0 && pri != ult) {
        remove_extremos(&n, &pri, &ult);
        if(pri != ult) {
            palind = 0;
        }
    }
    if(palind == 1)
        printf("palind");
    else
        printf("n palind");
}
