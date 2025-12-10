#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void push(Queue *q, int value) {
    q->data[q->rear++] = value;
}

int pop(Queue *q) {
    return q->data[q->front++];
}

int main() {
    int L;

    while (scanf("%d", &L) != EOF) {

        Queue q;
        initQueue(&q);

        for (int i = 0; i < L; i++) {
            int v;
            scanf("%d", &v);
            push(&q, v);
        }

        int maxSpeed = 0;
        while (!isEmpty(&q)) {
            int x = pop(&q);
            if (x > maxSpeed) maxSpeed = x;
        }

        if (maxSpeed < 10)
            printf("1\n");
        else if (maxSpeed < 20)
            printf("2\n");
        else
            printf("3\n");
    }

    return 0;
}
