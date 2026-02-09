#include <stdio.h>

int divisors(long long n) {
    int count = 0;

    for (int i = 1; i*i <= n; i++) {
        if (n % i != 0) continue;
        count += 2;
    }

    return count;
}

int main(void) {
    long long sum = 0;
    for (int i = 1; divisors(sum) < 500; i++) {
        sum += i;
    }

    printf("%lld\n", sum);
}
