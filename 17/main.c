#include <stdio.h>
#include <stdbool.h>

int letters_in_num(int num) {
    static const int ones[] = {
        0,
        sizeof("one") - 1,
        sizeof("two") - 1,
        sizeof("three") - 1,
        sizeof("four") - 1,
        sizeof("five") - 1,
        sizeof("six") - 1,
        sizeof("seven") - 1,
        sizeof("eight") - 1,
        sizeof("nine") - 1,
        sizeof("ten") - 1,
        sizeof("eleven") - 1,
        sizeof("twelve") - 1,
        sizeof("thirteen") - 1,
        sizeof("fourteen") - 1,
        sizeof("fifteen") - 1,
        sizeof("sixteen") - 1,
        sizeof("seventeen") - 1,
        sizeof("eighteen") - 1,
        sizeof("nineteen") - 1,
    };

    static const int tens[] = {
        0,
        sizeof("ten") - 1,
        sizeof("twenty") - 1,
        sizeof("thirty") - 1,
        sizeof("forty") - 1,
        sizeof("fifty") - 1,
        sizeof("sixty") - 1,
        sizeof("seventy") - 1,
        sizeof("eighty") - 1,
        sizeof("ninety") - 1,
    };

    int count = 0;

    if (num / 1000 % 10 != 0) {
        count += ones[num / 1000 % 10] + sizeof("thousand") - 1;
    }

    if (num / 100 % 10 != 0) {
        if (num % 100 != 0) count += 3;
        count += ones[num / 100 % 10] + sizeof("hundred") - 1;
    }

    if (num % 100 < 20) {
        count += ones[num % 100];
    } else {
        count += tens[num / 10 % 10];
        count += ones[num % 10];
    }

    return count;
}

int main(void) {
    int sum = 0;

    for (int i = 1; i <= 1000; i++) {
        sum += letters_in_num(i);
    }

    printf("%d\n", sum);

    return 0;
}
