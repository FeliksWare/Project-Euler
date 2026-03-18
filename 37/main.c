#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n < 2) return false;

    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

bool is_left_truncable_prime(int n) {
    int m = 1;

    do {
        m *= 10;
        if (!is_prime(n % m)) return false;
    } while (n % m < n);

    return true;
}

bool is_right_truncable_prime(int n) {
    while (n) {
        if (!is_prime(n)) return false;
        n /= 10;
    }

    return true;
}

bool is_truncable_prime(int n) {
    return is_left_truncable_prime(n) && is_right_truncable_prime(n);
}

int main(void) {
    int sum = 0;

    for (int c = 0, i = 10; c < 11; i++) {
        if (!is_truncable_prime(i)) continue;

        sum += i;
        c++;
    }

    printf("%d\n", sum);

    return 0;
}
