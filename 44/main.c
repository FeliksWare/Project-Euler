#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

long long pentagonal_number(long long n) {
    return n * (3*n - 1) / 2;
}

bool is_pentagonal_number(long long n) {
    // P = n(3n - 1) / 2 => 2P = 3n^2 - n => 0 = 3n^2 - n - 2P
    // a = 3, b = -1, c = -2P
    // b^2 - 4ac => 1 - 4 * 3 * -2P => 1 + 24P
    long long a = 1 + 24*n;
    double b = sqrt((double)a);
    if (b != round(b)) return false;
    a = b;
    return (1 + a) % 6 == 0;
}

bool property(long long i, long long j) {
    long long n = pentagonal_number(i);
    long long m = pentagonal_number(j);

    return is_pentagonal_number(n + m) && is_pentagonal_number(llabs(n - m));
}

int main(void) {
    long long i = 0;
    long long j = 0;

    bool found = false;
    while (!found) {
        i += 1;

        for (j = 1; j <= i; j++) {
            if (!property(i, j)) continue;

            found = true;
            break;
        }
    }

    printf("%lld\n", llabs(pentagonal_number(i) - pentagonal_number(j)));

    return 0;
}
