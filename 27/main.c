#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n < 2) return false;

    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int quadratic(int n, int a, int b) {
    return n*n + a*n + b;
}

int consecutive_primes(int a, int b) {
    int i = 0;
    while (is_prime(quadratic(i, a, b))) {
        i++;
    }
    return i;
}

int main(void) {
    int product = 0;
    int max_length = 0;

    for (int b = -1000; b <= 1000; b++) {
        if (!is_prime(b)) continue;

        for (int a = -999; a <= 999; a++) {
            int length = consecutive_primes(a, b);
            if (max_length < length) {
                product = a * b;
                max_length = length;
            }
        }
    }

    printf("%d\n", product);

    return 0;
}
