#include <stdio.h>
#include <stdbool.h>

bool concatenated_product_impl(long long n, long long target, int i) {
    if (n == target * i) return true;

    int m = 10;

    while (n % m < n) {
        if (n / m == target * i) {
            if (concatenated_product_impl(n % m, target, i + 1)) return true;
        }

        m *= 10;
    }

    return false;
}

bool concatenated_product(long long n) {
    int m = 10;

    while (n % m < n) {
        if (concatenated_product_impl(n % m, n / m, 2)) return true;

        m *= 10;
    }

    return false;
}

int main(void) {
    for (long long i = 987654321; i >= 918273645; i--) {
        unsigned char digits[10] = {0};

        long long j = i;
        while (j) {
            digits[j % 10] += 1;
            j /= 10;
        }

        if (digits[0] != 0) continue;

        bool pandigital = true;

        for (int k = 1; k < 10; k++) {
            if (digits[k] != 1) {
                pandigital = false;
                break;
            }
        }

        if (!pandigital) continue;

        if (concatenated_product(i)) {
            printf("%lld\n", i);
            break;
        }
    }

    return 0;
}
