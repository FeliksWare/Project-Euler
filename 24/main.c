#include <stddef.h>
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

void debug_array(int *array, size_t length) {
    printf("[");
    for (size_t i = 0; i < length; i++) {
        printf("%d", array[i]);
        if (i != length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main(void) {
    int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 1000000 - 1; i++) {
        next_permutation(nums, ARRAY_LENGTH(nums));
    }

    for (size_t i = 0; i < ARRAY_LENGTH(nums); i++) {
        printf("%d", nums[i]);
    }
    printf("\n");

    return 0;
}
