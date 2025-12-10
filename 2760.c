#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char text[1100];
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front, *rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

void enqueue(Queue *q, char *str) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->text, str);
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

char* dequeue(Queue *q) {
    if (q->front == NULL) return NULL;

    Node *temp = q->front;
    char *str = temp->text;

    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;

    return str;
}

void print10(char *s) {
    for (int i = 0; i < 10 && s[i] != '\0'; i++)
        printf("%c", s[i]);
}

int main() {
    char A[1100], B[1100], C[1100];
    fgets(A, 1100, stdin);
    fgets(B, 1100, stdin);
    fgets(C, 1100, stdin);

    A[strcspn(A, "\n")] = '\0';
    B[strcspn(B, "\n")] = '\0';
    C[strcspn(C, "\n")] = '\0';

    Queue q;
    initQueue(&q);

    enqueue(&q, A);
    enqueue(&q, B);
    enqueue(&q, C);

    printf("%s%s%s\n", A, B, C);
    printf("%s%s%s\n", B, C, A);
    printf("%s%s%s\n", C, A, B);

    print10(A);
    print10(B);
    print10(C);
    printf("\n");

    return 0;
}
