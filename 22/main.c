#include <stdio.h>
#include <ctype.h>

int main(void) {
    FILE *file = fopen("0022_names.txt", "r");

    char buffer[256];

    long long sum = 0;
    for (long long i = 1; fgets(buffer, sizeof(buffer), file) != NULL; i++) {
        long long value = 0;
        for (long long j = 0; buffer[j] != '\0'; j++) {
            if (!isalpha(buffer[j])) continue;
            value += buffer[j] - 'A' + 1;
        }

        sum += value * i;
    }

    fclose(file);

    printf("%lld\n", sum);

    return 0;
}
