#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATE 100000

int invert_number(int x) {
    char s[20];
    sprintf(s, "%d", x);
    int len = strlen(s);
    for (int i = 0; i < len/2; i++) {
        char tmp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = tmp;
    }
    return atoi(s);
}

int bfs(int start, int goal) {
    static int dist[MAX_STATE];
    for (int i = 0; i < MAX_STATE; i++) {
        dist[i] = -1;
    }

    int *queue = malloc(sizeof(int) * MAX_STATE);
    int head = 0, tail = 0;

    dist[start] = 0;
    queue[tail++] = start;

    while (head < tail) {
        int u = queue[head++];
        if (u == goal) {
            free(queue);
            return dist[u];
        }
        int v1 = u + 1;
        if (v1 < MAX_STATE && dist[v1] == -1) {
            dist[v1] = dist[u] + 1;
            queue[tail++] = v1;
        }
        int v2 = invert_number(u);
        if (v2 < MAX_STATE && dist[v2] == -1) {
            dist[v2] = dist[u] + 1;
            queue[tail++] = v2;
        }
    }

    free(queue);
    return -1; 
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        int A, B;
        scanf("%d %d", &A, &B);
        if (A == B) {
            printf("0\n");
        } else {
            printf("%d\n", bfs(A, B));
        }
    }

    return 0;
}