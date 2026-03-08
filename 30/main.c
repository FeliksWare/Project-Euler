#include <stdio.h>

int fifth_power(int n) {
    return n*n*n*n*n;
}

int upper_bound(void) {
    int n = 9;
    int s = fifth_power(9);

    while (n < s) {
        n = n*10 + 9;
        s += fifth_power(9);
    }

    return n;
}

int fifth_power_sum_of_digits(int n) {
    int s = 0;

    while (n) {
        s += fifth_power(n % 10);
        n /= 10;
    }

    return s;
}

int main(void) {
    int s = 0;

    for (int i = 10; i < upper_bound(); i++) {
        if (fifth_power_sum_of_digits(i) == i) {
            s += i;
        }
    }

    printf("%d\n", s);

    return 0;
}
