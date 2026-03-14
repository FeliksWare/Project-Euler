#include <stdio.h>
#include <stdbool.h>

int factorial(int n) {
    int f = 1;
    while (n) {
        f *= n;
        n -= 1;
    }
    return f;
}

int curious_number_upper_bound(void) {
    int n = 9;
    int f = factorial(9);

    while (n < f) {
        n = n*10 + 9;
        f += factorial(9);
    }

    return n;
}

int factorial_sum_of_digits(int n) {
    int sum = 0;

    while (n) {
        sum += factorial(n % 10);
        n /= 10;
    }

    return sum;
}

int is_curious_number(int n) {
    return factorial_sum_of_digits(n) == n;
}

int main(void) {
    int sum = 0;

    for (int i = 10; i < curious_number_upper_bound(); i++) {
        if (!is_curious_number(i)) continue;

        sum += i;
    }

    printf("%d\n", sum);

    return 0;
}
