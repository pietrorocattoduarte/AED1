#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 1000000000

int main() {
    int n, e;
    while (1) {
        scanf("%d %d", &n, &e);
        if (n == 0 && e == 0) break;

        int dist[n+1][n+1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) dist[i][j] = 0;
                else dist[i][j] = INF;
            }
        }

        for (int i = 0; i < e; i++) {
            int x, y, h;
            scanf("%d %d %d", &x, &y, &h);

            if (dist[y][x] != INF) {
                dist[x][y] = 0;
                dist[y][x] = 0;
            } else {
                dist[x][y] = h;
            }
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        if (dist[i][j] > dist[i][k] + dist[k][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                }
            }
        }

        int q;
        scanf("%d", &q);

        for (int i = 0; i < q; i++) {
            int a, b;
            scanf("%d %d", &a, &b);

            if (dist[a][b] >= INF)
                printf("Nao e possivel entregar a carta\n");
            else
                printf("%d\n", dist[a][b]);
        }

        printf("\n");
    }

    return 0;
}
