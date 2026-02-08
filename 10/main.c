#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

static bool primes[2000000];

int main(void) {
    long long summation = 0;

    for (size_t i = 0; i < 2000000; i++) {
        primes[i] = true;
    }

    primes[0] = false;
    primes[1] = false;

    for (size_t i = 0; i < 2000000; i++) {
        if (!primes[i]) continue;

        summation += i;

        for (size_t j = i * i; j < 2000000; j += i) {
            primes[j] = false;
        }
    }

    printf("%lld\n", summation);

    return 1;
}
