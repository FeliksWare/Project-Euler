#include <stdio.h>

int main(void) {
    long long start = 1;
    long long length = 0;

    for (long long i = 1; i < 1000000; i++) {
        long long n = i;
        long long count;

        for (count = 0; n != 1; count++) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = 3*n + 1;
            }
        }

        if (count > length) {
            start = i;
            length = count;
        }
    }

    printf("%lld\n", start);

    return 0;
}
