#include <stdio.h>
#include <stdbool.h>

bool is_curious(int a, int b) {
    if (a == b) return false;

    int a_tens = a / 10, a_ones = a % 10;
    int b_tens = b / 10, b_ones = b % 10;

    if (a_tens == b_ones) {
        return b_tens * a == b * a_ones;
    }

    if (b_tens == a_ones) {
        return a_tens * b == a * b_ones;
    }

    return false;
}

int main(void) {
    int numerator = 1;
    int denominator = 1;

    for (int a = 10; a < 100; a++) {
        for (int b = a; b < 100; b++) {
            if (!is_curious(a, b)) continue;

            numerator *= a;
            denominator *= b;
        }
    }

    for (int i = 2; i <= numerator && i <= denominator; i++) {
        while (numerator % i == 0 && denominator % i == 0) {
            numerator /= i;
            denominator /= i;
        }
    }

    printf("%d\n", denominator);

    return 0;
}
