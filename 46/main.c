#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n < 2) return false;

    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

bool goldbach(int n) {
    if (n % 2 == 0) return true;
    if (is_prime(n)) return true;

    for (int i = 0; i < n; i++) {
        if (!is_prime(i)) continue;

        double m = sqrt((double)(n - i) / 2.0);
        if (m == round(m)) return true;
    }

    return false;
}

int main(void) {
    int i = 2;

    while (goldbach(i)) {
        i += 1;
    }

    printf("%d\n", i);

    return 0;
}
