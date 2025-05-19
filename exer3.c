int parity(int n) {
    if(n % 2 == 0)
        return 0;
    else
        return 1;
}

int k_alternate(int *n) {
    int size, odd, even, k;
    size = *n;
    scanf("%d", n);

    for(i = 1; i < size; i++) {
        if(parity(n))
            while(parity(n)) {
                even += 1;
                scanf("%d", n);
            }
        else
            while(!parity(n)) {
                odd += 1;
                scanf("%d", n);
            }
        if(k == 0 && even == 0)
            k = odd;
        else
            k = even;
    }
}

void main() {
    int n;

    printf("Tamaho?");
    scanf("%d", &n);

    k_alternate(&n);

    }
}
