#include <stdio.h>

int main() {
    int N, M;
    while (scanf("%d %d", &N, &M) == 2) {
        if (N == 0 && M == 0) break;

        char grid[55][55];
        for (int i = 0; i < N; i++) {
            scanf("%s", grid[i]);
        }

        int qr[3000], qc[3000];
        int head = 0, tail = 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (grid[i][j] == 'T') {
                    qr[tail] = i;
                    qc[tail] = j;
                    tail++;
                }

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (head < tail) {
            int r = qr[head], c = qc[head];
            head++;
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr >= 0 && nr < N && nc >= 0 && nc < M && grid[nr][nc] == 'A') {
                    grid[nr][nc] = 'T';
                    qr[tail] = nr;
                    qc[tail] = nc;
                    tail++;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            printf("%s\n", grid[i]);
        }
        printf("\n");
    }
    return 0;
}
