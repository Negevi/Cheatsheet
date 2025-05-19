void to_hms(int secs, int *h, int *m, int *s) {
    *h = secs / 3600;
    *m = secs / 60 % 60;
    *s = secs % 60 % 60;
}

void main() {
    int h, m, s;
    to_hms(10000, &h, &m, &s);
    printf("h:%d m:%d s:%d", h, m, s);
}
