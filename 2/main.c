#include <stdio.h>

int main(void) {
    int sum = 0;

    int a = 1;
    int b = 2;
    while (b < 4000000) {
        if (b % 2 == 0) {
            sum += b;
        }

        int c = a + b;
        a = b;
        b = c;
    }

    printf("Sum: %d\n", sum);

    return 0;
}
