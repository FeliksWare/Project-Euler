#include <stdio.h>

int main(void) {
    for (int a = 1; a <= 1000; a++) {
        for (int b = a + 1; 2*b - a < 1000; b++) {
            int c = 1000 - b - a;

            if (a*a + b*b == c*c) {
                printf("%d\n", a*b*c);
                return 0;
            }
        }
    }

    return 1;
}
