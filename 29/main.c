#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int base, exponent;
    struct Node *l, *r;
};

struct Node* new_node(int base, int exponent) {
    struct Node *node = malloc(sizeof(struct Node));
    *node = (struct Node){base, exponent, NULL, NULL};
    return node;
}

void add_node(struct Node **root, struct Node *node) {
    while (*root != NULL) {
        if (node->base > (*root)->base) {
            root = &(*root)->r;
        } else if (node->base < (*root)->base) {
            root = &(*root)->l;
        } else if (node->exponent > (*root)->exponent) {
            root = &(*root)->r;
        } else if (node->exponent < (*root)->exponent) {
            root = &(*root)->l;
        } else {
            return;
        }
    }

    *root = node;
}

int count_nodes(struct Node *node) {
    if (node == NULL) return 0;
    return count_nodes(node->l) + count_nodes(node->r) + 1;
}

void decompose(int n, int *result_base, int *result_exponent) {
    int original_n = n;
    int base = 1;
    int exponent = 0;

    for (int i = 2; i <= n; i++) {
        int current_exponent = 0;

        if (n % i == 0) {
            base *= i;
        } else {
            continue;
        }

        while (n % i == 0) {
            current_exponent++;
            n /= i;
        }

        if (exponent == 0) {
            exponent = current_exponent;
        } else if (exponent != current_exponent) {
            base = original_n;
            exponent = 1;
            break;
        }
    }

    *result_base = base;
    *result_exponent = exponent;
}

int main(void) {
    struct Node *root = NULL;

    for (int a = 2; a <= 100; a++) {
        int a_base, a_exponent;
        decompose(a, &a_base, &a_exponent);

        for (int b = 2; b <= 100; b++) {
            add_node(&root, new_node(a_base, a_exponent * b));
        }
    }

    printf("%d\n", count_nodes(root));

    return 0;
}
