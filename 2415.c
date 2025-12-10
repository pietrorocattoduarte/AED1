#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front, *rear;
    int size;
} Queue;

void init(Queue *q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

void push(Queue *q, int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
    q->size++;
}

void clear(Queue *q) {
    Node *temp;
    while (q->front != NULL) {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    q->rear = NULL;
    q->size = 0;
}

int main() {
    int n, x;
    scanf("%d", &n);

    Queue q;
    init(&q);

    int prev = -1;
    int maxSeq = 1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        if (i == 0 || x == prev) {
            push(&q, x);
        } else {
            if (q.size > maxSeq)
                maxSeq = q.size;
            clear(&q);
            push(&q, x);
        }

        prev = x;
    }

    if (q.size > maxSeq)
        maxSeq = q.size;

    printf("%d\n", maxSeq);

    return 0;
}
