#include <stdio.h>

int main(void) {
    long long sum = 0;

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (i == j) continue;
            sum += i*j;
        }
    }

    printf("%lld\n", sum);

    return 0;
}
