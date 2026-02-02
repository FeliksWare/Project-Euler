#include <stdio.h>
#include <stdbool.h>

static int primes[10001] = {0};
int length = 0;

int main(void) {
    for (int i = 2; length < 10001; i++) {
        bool is_prime = true;

        for (int j = 0; j < length; j++) {
            if (i % primes[j] == 0) {
                is_prime = false;
                break;
            }
        }

        if (!is_prime) {
            continue;
        }

        primes[length++] = i;
    }

    printf("%d\n", primes[10000]);

    return 0;
}
