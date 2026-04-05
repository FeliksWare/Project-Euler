#include <stdio.h>
#include <stdbool.h>

int distinct_prime_factors(int n) {
    int count = 0;

    for (int i = 2; i <= n; i++) {
        if (n % i != 0) continue;

        while (n % i == 0) {
            n /= i;
        }

        count += 1;
    }

    return count;
}

bool consecutive_distinct_prime_factors(int first, int n) {
    for (int i = 0; i < n; i++) {
        if (distinct_prime_factors(first + i) != n) return false;
    }

    return true;
}

int main(void) {
    for (int i = 0;; i++) {
        if (!consecutive_distinct_prime_factors(i, 4)) continue;

        printf("%d\n", i);
        break;
    }

    return 0;
}
