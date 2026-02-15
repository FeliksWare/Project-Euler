#include <stdlib.h>
#include <stdio.h>

struct Array {
    int *array;
    size_t count;
    size_t capacity;
};

void array_reserve(struct Array *array, size_t minimum) {
    if (array->capacity >= minimum) {
        return;
    }

    if (array->capacity == 0) {
        array->capacity = 1024;
    }

    while (array->capacity < minimum) {
        array->capacity *= 2;
    }

    array->array = realloc(array->array, sizeof(int) * array->capacity);
}

void array_push(struct Array *array, int value) {
    array_reserve(array, array->count + 1);
    array->array[array->count++] = value;
}

void free_array(struct Array *array) {
    if (array->array != NULL) {
        free(array->array);
    }
    *array = (struct Array){0};
}

void double_array(struct Array *array) {
    int temp = 0;

    for (size_t i = 0; i < array->count; i++) {
        temp += array->array[i] * 2;
        array->array[i] = temp % 10;
        temp /= 10;
    }

    if (temp != 0) {
        array_push(array, temp);
    }
}

int main(void) {
    struct Array array = {0};
    array_push(&array, 1);

    for (int i = 0; i < 1000; i++) {
        double_array(&array);
    }

    long long sum = 0;

    for (size_t i = 0; i < array.count; i++) {
        sum += array.array[i];
    }

    printf("%lld\n", sum);

    return 0;
}
