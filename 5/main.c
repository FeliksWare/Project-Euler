#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int n[19];

    for (int i = 0; i < 19; i++) {
        n[i] = i + 2;
    }

    int t = 1;

    int f = 2;
    for (;;) {
        bool done = true;
        bool divisible = false;

        for (int i = 0; i < 19; i++) {
            if (n[i] % f == 0) {
                n[i] /= f;
                divisible = true;
            }

            if (n[i] != 1) {
                done = false;
            }
        }

        if (divisible) {
            t *= f;
        } else {
            f += 1;
        }

        if (done) {
            break;
        }
    }

    printf("%d\n", t);

    return 0;
}
