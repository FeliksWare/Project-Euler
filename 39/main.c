#include <stdio.h>

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(*x))

int main(void) {
    int perimeters[1000] = {0};

    for (int a = 1; a < 1000; a++) {
        for (int b = a; a+b < 1000; b++) {
            for (int c = b; a+b+c < 1000; c++) {
                if (a*a + b*b != c*c) continue;
                perimeters[a+b+c] += 1;
            }
        }
    }

    int maximum_p = 0;
    int p = 0;

    for (size_t i = 0; i < ARRAY_LENGTH(perimeters); i++) {
        if (perimeters[i] > maximum_p) {
            maximum_p = perimeters[i];
            p = i;
        }
    }

    printf("%d\n", p);

    return 0;
}
