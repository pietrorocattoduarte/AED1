#include <stdio.h>
#define MAX 1000

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        int stack[MAX], queue[MAX], pqueue[MAX];
        int top = -1, front = 0, rear = 0, pq = 0;
        int is_stack = 1, is_queue = 1, is_pq = 1;

        for (int i = 0; i < n; i++) {
            int op, x;
            scanf("%d %d", &op, &x);

            if (op == 1) {
                stack[++top] = x;
                queue[rear++] = x;
                int j = pq - 1;
                while (j >= 0 && pqueue[j] < x) {
                    pqueue[j + 1] = pqueue[j];
                    j--;
                }
                pqueue[j + 1] = x;
                pq++;
            } else {
                if (is_stack && (top < 0 || stack[top--] != x)) is_stack = 0;
                if (is_queue && (front == rear || queue[front++] != x)) is_queue = 0;
                if (is_pq && (pq == 0 || pqueue[0] != x)) is_pq = 0;
                if (is_pq) {
                    for (int j = 1; j < pq; j++) pqueue[j - 1] = pqueue[j];
                    pq--;
                }
            }
        }

        int total = is_stack + is_queue + is_pq;
        if (total == 0) printf("impossible\n");
        else if (total > 1) printf("not sure\n");
        else if (is_stack) printf("stack\n");
        else if (is_queue) printf("queue\n");
        else printf("priority queue\n");
    }
    return 0;
}
