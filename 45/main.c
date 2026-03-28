#include <stdio.h>

long long triangle_number(long long n) {
    return n * (n + 1) / 2;
}

long long pentagonal_number(long long n) {
    return n * (3*n - 1) / 2;
}

long long hexagonal_number(long long n) {
    return n * (2*n - 1);
}

int main(void) {
    long long i = 285 + 1;
    long long j = 165;
    long long k = 143;

    while (triangle_number(i) != pentagonal_number(j) || triangle_number(i) != hexagonal_number(k)) {
        if (hexagonal_number(k) < triangle_number(i)) {
            k += 1;
        }

        if (pentagonal_number(j) < hexagonal_number(k)) {
            j += 1;
        }

        if (triangle_number(i) < pentagonal_number(j)) {
            i += 1;
        }
    }

    printf("%lld\n", triangle_number(i));

    return 0;
}
