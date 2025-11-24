#include <stdio.h>
#include <stdlib.h>

#define MAXN 26

int adj[MAXN][MAXN];
int visited[MAXN];
int n;

void collect_component(int u, int comp[], int *cnt) {
    visited[u] = 1;
    comp[(*cnt)++] = u;
    for (int v = 0; v < n; v++) {
        if (adj[u][v] && !visited[v])
            collect_component(v, comp, cnt);
    }
}

int cmp_int(const void *a, const void *b) {
    return (*(int*)a) - (*(int*)b);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    for (int caso = 1; caso <= t; caso++) {
        int e;
        scanf("%d %d", &n, &e);
        for (int i = 0; i < n; i++) {
            visited[i] = 0;
            for (int j = 0; j < n; j++)
                adj[i][j] = 0;
        }
        while (e--) {
            char a, b;
            scanf(" %c %c", &a, &b);
            int x = a - 'a';
            int y = b - 'a';
            adj[x][y] = adj[y][x] = 1;
        }

        int comp_count = 0;
        printf("Case #%d:\n", caso);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int comp[MAXN];
                int cnt = 0;
                collect_component(i, comp, &cnt);
                qsort(comp, cnt, sizeof(int), cmp_int);
                for (int k = 0; k < cnt; k++) {
                    printf("%c,", comp[k] + 'a');
                }
                printf("\n");
                comp_count++;
            }
        }

        printf("%d connected components\n\n", comp_count);
    }

    return 0;
}