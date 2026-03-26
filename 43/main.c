#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(x[0]))

// https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
bool next_permutation(int *array, size_t length) {
    size_t k = SIZE_MAX;

    for (size_t i = length - 1; i > 0; i--) {
        if (array[i - 1] < array[i]) {
            k = i - 1;
            break;
        }
    }

    if (k == SIZE_MAX) {
        return false;
    }

    size_t l = 0;

    for (size_t i = length - 1; i > k; i--) {
        if (array[k] < array[i]) {
            l = i;
            break;
        }
    }

    int temp = array[k];
    array[k] = array[l];
    array[l] = temp;

    size_t left = k + 1;
    size_t right = length - 1;

    while (left < right) {
        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;

        left += 1;
        right -= 1;
    }

    return true;
}

bool has_sub_string_prime_divisibility(int *d) {
    return (d[1] * 100 + d[2] * 10 + d[3]) % 2 == 0 &&
           (d[2] * 100 + d[3] * 10 + d[4]) % 3 == 0 &&
           (d[3] * 100 + d[4] * 10 + d[5]) % 5 == 0 &&
           (d[4] * 100 + d[5] * 10 + d[6]) % 7 == 0 &&
           (d[5] * 100 + d[6] * 10 + d[7]) % 11 == 0 &&
           (d[6] * 100 + d[7] * 10 + d[8]) % 13 == 0 &&
           (d[7] * 100 + d[8] * 10 + d[9]) % 17 == 0;
}

int main(void) {
    long long sum = 0;
    int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    do {
        if (!has_sub_string_prime_divisibility(num)) continue;
        for (size_t i = ARRAY_LENGTH(num), m = 1; i > 0; i--, m *= 10) {
            sum += num[i-1] * m;
        }
    } while (next_permutation(num, ARRAY_LENGTH(num)));

    printf("%lld\n", sum);

    return 0;
}
