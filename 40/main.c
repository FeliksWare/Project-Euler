#include <stdio.h>

int get_digit(int index) {
    int n = 0;
    int m = 1;

    for (;;) {
        for (int i = m; i > 0; i /= 10) {
            if (index <= 0) return (n / i) % 10;
            index--;
        }

        n++;
        if (n / 10 / m) m *= 10;
    }
}

int main(void) {
    int p = 1;

    for (int i = 0, j = 1; i < 7; i++, j *= 10) {
        p *= get_digit(j);
    }

    printf("%d\n", p);

    return 0;
}
