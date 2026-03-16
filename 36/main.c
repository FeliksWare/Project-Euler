#include <stdio.h>
#include <stdbool.h>

bool is_parlindrome_base(int n, int b) {
    int t = n;
    int r = 0;

    while (t) {
        r = r * b + (t % b);
        t /= b;
    }

    return n == r;
}

int main(void) {
    int sum = 0;

    for (int i = 1; i < 1000000; i++) {
        if (!is_parlindrome_base(i, 2)) continue;
        if (!is_parlindrome_base(i, 10)) continue;

        sum += i;
    }

    printf("%d\n", sum);

    return 0;
}
