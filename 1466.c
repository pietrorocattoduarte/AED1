#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left, *right;
} Node;

Node* insert(Node *root, int x) {
    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        root->value = x;
        root->left = root->right = NULL;
    }
    else if (x < root->value) {
        root->left = insert(root->left, x);
    }
    else {
        root->right = insert(root->right, x);
    }
    return root;
}
typedef struct queue {
    Node *data[1000];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

int empty(Queue *q) {
    return q->front == q->rear;
}

void push(Queue *q, Node *x) {
    q->data[q->rear++] = x;
}

Node* pop(Queue *q) {
    return q->data[q->front++];
}
void levelOrder(Node *root) {
    Queue q;
    initQueue(&q);

    push(&q, root);
    int first = 1;

    while (!empty(&q)) {
        Node *n = pop(&q);

        if (!first) printf(" ");
        printf("%d", n->value);
        first = 0;

        if (n->left) push(&q, n->left);
        if (n->right) push(&q, n->right);
    }
}
int main() {
    int C, N, x;

    scanf("%d", &C);
    for (int c = 1; c <= C; c++) {

        Node *root = NULL;

        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &x);
            root = insert(root, x);
        }

        printf("Case %d:\n", c);
        levelOrder(root);
        printf("\n\n");
    }

    return 0;
}
