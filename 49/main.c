#include <stdio.h>
#include <stdbool.h>

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(x[0]))

int main(void) {
    bool primes[10000] = {0};

    for (size_t i = 0; i < ARRAY_LENGTH(primes); i++) {
        primes[i] = true;
    }

    primes[0] = false;
    primes[1] = false;

    for (size_t i = 0; i < ARRAY_LENGTH(primes); i++) {
        if (!primes[i]) continue;

        for (size_t j = i * i; j < ARRAY_LENGTH(primes); j += i) {
            primes[j] = false;
        }
    }

    for (size_t i = 1000; i < ARRAY_LENGTH(primes); i++) {
        if (!primes[i]) continue;

        for (size_t j = 1; i + 2 * j < ARRAY_LENGTH(primes); j++) {
            if (!primes[i + 1 * j]) continue;
            if (!primes[i + 2 * j]) continue;

            int digits0[10] = {0};
            int digits1[10] = {0};
            int digits2[10] = {0};

            size_t n = i + 0*j;
            while (n) {
                digits0[n % 10] += 1;
                n /= 10;
            }

            n = i + 1*j;
            while (n) {
                digits1[n % 10] += 1;
                n /= 10;
            }

            n = i + 2*j;
            while (n) {
                digits2[n % 10] += 1;
                n /= 10;
            }

            bool found = true;

            for (size_t k = 0; k < ARRAY_LENGTH(digits0); k++) {
                if (digits0[k] == digits1[k] && digits1[k] == digits2[k]) continue;
                found = false;
                break;
            }

            if (!found) continue;

            printf("%zu%zu%zu\n", i, i + j, i + 2 * j);
        }
    }

    return 0;
}
