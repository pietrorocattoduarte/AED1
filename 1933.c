#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

// Insere no início (lista pequena, qualquer método serve)
Node* insert(Node *head, int x) {
    Node *n = malloc(sizeof(Node));
    n->value = x;
    n->next = head;
    return n;
}

int maxValue(Node *head) {
    int max = head->value;
    Node *curr = head->next;

    while (curr != NULL) {
        if (curr->value > max)
            max = curr->value;
        curr = curr->next;
    }

    return max;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    Node *head = NULL;

    head = insert(head, a);
    head = insert(head, b);

    int result = maxValue(head);

    printf("%d\n", result);

    return 0;
}
