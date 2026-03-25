#include <stdio.h>
#include <stdbool.h>

bool is_pandigital(int n) {
    int digits[10] = {0};

    do {
        digits[n % 10] += 1;
        n /= 10;
    } while (n);

    if (digits[0] != 0) return false;

    for (n = 1; n < 10; n++) {
        if (digits[n] > 1) return false;
        if (digits[n] == 0) break;
    }

    for (; n < 10; n++) {
        if (digits[n] != 0) return false;
    }

    return true;
}

bool is_prime(int n) {
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(void) {
    for (int i = 9999999; i >= 0; i--) {
        if (!is_pandigital(i)) continue;
        if (!is_prime(i)) continue;

        printf("%d\n", i);
        break;
    }

    return 0;
}
