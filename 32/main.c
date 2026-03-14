#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int value;
    struct Node *l, *r;
};

struct Node* new_node(int value) {
    struct Node *node = malloc(sizeof(struct Node));
    *node = (struct Node){value, NULL, NULL};
    return node;
}

void add_node(struct Node **root, struct Node *node) {
    while (*root != NULL) {
        if (node->value < (*root)->value) {
            root = &(*root)->l;
        } else if (node->value > (*root)->value) {
            root = &(*root)->r;
        } else {
            return;
        }
    }

    *root = node;
}

int sum_nodes(struct Node *node) {
    if (node == NULL) return 0;
    return sum_nodes(node->l) + sum_nodes(node->r) + node->value;
}

bool pandigital_product(int a, int b) {
    int c = a * b;

    int digits[10] = {0};

    while (a) {digits[a % 10] += 1; a /= 10;}
    while (b) {digits[b % 10] += 1; b /= 10;}
    while (c) {digits[c % 10] += 1; c /= 10;}

    if (digits[0] != 0) return false;

    for (int i = 1; i < 10; i++) {
        if (digits[i] != 1) return false;
    }

    return true;
}

int main(void) {
    struct Node *root = NULL;

    for (int a = 0; a < 10000; a++) {
        for (int b = a; b < 10000; b++) {
            if (!pandigital_product(a, b)) continue;
            add_node(&root, new_node(a * b));

            printf("%d * %d = %d\n", a, b, a * b);
        }
    }

    printf("%d\n", sum_nodes(root));

    return 0;
}
