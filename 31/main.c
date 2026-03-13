#include <stdio.h>

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(x[0]))

int coin_values[] = {200, 100, 50, 20, 10, 5, 2, 1};

int count_coins(int target, size_t index) {
    int count = 0;

    while (target > 0) {
        if (index < ARRAY_LENGTH(coin_values) - 1) {
            count += count_coins(target, index + 1);
        }
        target -= coin_values[index];
    }

    if (target == 0) {
        count += 1;
    }

    return count;
}

int main(void) {
    printf("%d\n", count_coins(200, 0));

    return 0;
}
