#include <stdio.h>
#include <stdbool.h>

int sum_of_proper_divisors(int n) {
    int sum = 0;

    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    return sum;
}

bool is_amicable(int n) {
    int m = sum_of_proper_divisors(n);
    if (n == m) return false;
    return sum_of_proper_divisors(m) == n;
}

int main(void) {
    int sum = 0;

    for (int i = 1; i < 10000; i++) {
        if (is_amicable(i)) {
            sum += i;
        }
    }

    printf("%d\n", sum);

    return 0;
}
