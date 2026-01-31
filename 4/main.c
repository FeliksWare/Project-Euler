#include <stdio.h>
#include <stdbool.h>

bool is_palindrome(int n) {
    int t = n;
    int r = 0;

    while (t != 0) {
        r = (r * 10) + (t % 10);
        t /= 10;
    }

    return n == r;
}

int main(void) {
    int palindrome = 0;

    for (int i = 100; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            int product = i*j;

            if (product > palindrome && is_palindrome(product)) {
                palindrome = product;
            }
        }
    }

    printf("palindrome: %d\n", palindrome);

    return 0;
}
