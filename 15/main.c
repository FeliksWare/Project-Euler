#include <stdio.h>

#define MAX_SIZE (20)

static long long lattice_results[(MAX_SIZE + 1)*(MAX_SIZE + 1)] = {0};

long long lattice(int w, int h) {
    if (w <= 0 || h <= 0) return 1;

    long long result = 0;

    if (w <= MAX_SIZE && h <= MAX_SIZE) {
        result = lattice_results[h*(MAX_SIZE + 1) + w];
        if (result != 0) return result;

        result = lattice(w, h - 1) + lattice(w - 1, h);
        lattice_results[h*(MAX_SIZE + 1) + w] = result;
        lattice_results[w*(MAX_SIZE + 1) + h] = result;
        return result;
    }
    
    return lattice(w, h - 1) + lattice(w - 1, h);
}

int main(void) {
    printf("%lld\n", lattice(20, 20));

    return 0;
}
