#include <stdio.h>

int main(void) {
    long long n = 600851475143;
    long long i;
    
    for (i = 2; i*i <= n; i++) {
        while (n % i == 0) {
            n /= i;
        }
    }

    printf("Factor: %lld\n", n);

    return 0;
}
