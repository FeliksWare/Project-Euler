#include <stdio.h>
#include <stdlib.h>

#define ARRAY_INITIAL_SIZE (1024)
#define ARRAY_GROWTH_RATE (2)

struct Array {
    int *array;
    size_t capcity;
    size_t count;
};

void array_reserve(struct Array *array, size_t minimum) {
    if (array->capcity > minimum) return;

    if (array->capcity == 0) {
        array->capcity = ARRAY_INITIAL_SIZE;
    }

    while (array->capcity < minimum) {
        array->capcity *= ARRAY_GROWTH_RATE;
    }

    array->array = realloc(array->array, sizeof(*array->array) * array->capcity);
}

void array_push(struct Array *array, int value) {
    array_reserve(array, array->count + 1);
    array->array[array->count++] = value;
}

void free_array(struct Array *array) {
    if (array->array) {
        free(array->array);
    }
    *array = (struct Array){0};
}

int recurring_length(int x) {
    struct Array array = {0};
    int result = 0;

    int n = 10;

    for (int i = 0; n; i++) {
        for (int j = 0; j < array.count; j++) {
            if (array.array[j] == n) {
                result = i - j;
                goto safe_return;
            }
        }

        array_push(&array, n);
        n %= x;
        n *= 10;
    }

safe_return:
    return result;
}

int main(void) {
    int d = 0;
    int max_length = 0;

    for (int i = 1; i < 1000; i++) {
        int length = recurring_length(i);
        if (max_length < length) {
            d = i;
            max_length = length;
        }
    }

    printf("%d\n", d);

    return 0;
}
