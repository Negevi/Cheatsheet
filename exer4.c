#include <stdio.h>

unsigned long long potencia(unsigned int b, unsigned int e) {
    unsigned long long resp = b;
    for(e; e > 0; e--) {
        resp = resp * b;
    }
    return resp;
}

void main() {
    printf("%llu", potencia(2, 50));
}
