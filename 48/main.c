#include <stdio.h>
#include <stdbool.h>

int main(void) {
    long long sum = 0;

    for (long long i = 1; i <= 1000; i++) {
        long long prod = 1;

        for (long long j = 0; j < i; j++) {
            prod *= i;
            prod %= 10000000000ll;
        }

        sum += prod;
        sum %= 10000000000ll;
    }

    printf("%010lld\n", sum);

    return 0;
}
