#include <stdio.h>
#include <stdbool.h>

#define UPPER_LIMIT (28123)

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(x[0]))

static int sum_of_proper_divisors[UPPER_LIMIT + 2] = {0};

int main(void) {
    for (size_t i = 1; i < ARRAY_LENGTH(sum_of_proper_divisors); i++) {
        for (size_t j = i*2; j < ARRAY_LENGTH(sum_of_proper_divisors); j += i) {
            sum_of_proper_divisors[j] += i;
        }
    }

    int sum = 0;

    for (int i = 1; i <= UPPER_LIMIT; i++) {
        bool possible = false;

        for (int j = 1; j*2 <= i; j++) {
            if (sum_of_proper_divisors[j] <= j) continue;
            if (sum_of_proper_divisors[i - j] <= i - j) continue;

            possible = true;
            break;
        }

        if (!possible) {
            sum += i;
        }
    }

    printf("%d\n", sum);

    return 0;
}
