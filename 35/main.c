#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool* prime_mask(size_t length) {
    bool *primes = calloc(length, sizeof(bool));

    for (size_t i = 0; i < length; i++) {
        primes[i] = true;
    }

    if (length > 0) primes[0] = false;
    if (length > 1) primes[1] = false;

    for (size_t i = 0; i < length; i++) {
        if (!primes[i]) continue;

        for (size_t j = i * i; j < length; j += i) {
            primes[j] = false;
        }
    }

    return primes;
}

int circular_primes_below(size_t n) {
    bool *primes = prime_mask(n);
    int count = 0;

    size_t magnitude = 1;

    for (size_t i = 0; i < n; i++) {
        if (magnitude * 10 < i) {
            magnitude *= 10;
        }

        if (!primes[i]) continue;

        size_t j = i;

        do {
            if (!primes[j]) break;
            j = (j % 10) * magnitude + (j / 10);
        } while (i != j);

        if (i == j) {
            count += 1;
        }
    }

    free(primes);
    return count;
}

int main(void) {
    printf("%d\n", circular_primes_below(1000000));

    return 0;
}
