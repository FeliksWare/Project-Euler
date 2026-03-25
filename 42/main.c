#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_square_number(int n) {
    double m = sqrt((double)n);
    return m == round(m);
}

bool is_triangle_number(int n) {
    // t = 1/2 * n * (n + 1) => 2t = n^2 + n => n^2 + n - 2t = 0
    // a = 1, b = 1, c = -2t
    // b^2 - 4ac => 1^2 - 4 * 1 * -2t => 1 + 8t
    return is_square_number(1 + 8*n);
}

bool is_triangle_word(const char *word) {
    int sum = 0;

    for (size_t i = 0; word[i] != '\0' && word[i] != '\n'; i++) {
        sum += word[i] - 'A' + 1;
    }

    return is_triangle_number(sum);
}

int main(void) {
    int sum = 0;
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (buffer[0] == '\n') continue;

        if (!is_triangle_word(buffer)) continue;

        sum += 1;
    }

    printf("%d\n", sum);

    return 0;
}
