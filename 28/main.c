#include <stdio.h>
#include <stdlib.h>

int spiral(int x, int y, int width, int height) {
    int total = 0;
    int index = 1;

    int dx = 0;
    int dy = -1;

    while (abs(x) <= width && abs(y) <= height) {
        if (abs(x) == abs(y)) {
            total += index;
        }

        if(x == y || (x < 0 && x == -y) || (x > 0 && x == 1-y)) {
            int temp = dx;
            dx = -dy;
            dy = temp;
        }

        x += dx;
        y += dy;

        index++;
    }

    return total;
}

int main(void) {
    printf("%d\n", spiral(0, 0, 500, 500));

    return 0;
}
