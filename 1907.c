#include <stdio.h>
#include <stdlib.h>

typedef struct { 
    int r, c; 
} Node;

int main() {
    int A, B;
    if (scanf("%d %d\n", &A, &B) != 2) return 0;
    char **grid = malloc(A * sizeof(char*));
    for (int i = 0; i < A; i++) {
        grid[i] = malloc((B + 1) * sizeof(char));
        fgets(grid[i], B + 2, stdin);
        for (int j = 0; j < B; j++) {
            if (grid[i][j] == '\n') grid[i][j] = '\0';
        }
    }
    char **vis = malloc(A * sizeof(char*));
    for (int i = 0; i < A; i++) {
        vis[i] = calloc(B, sizeof(char));
    }
    Node *stack = malloc(A * B * sizeof(Node));
    int top;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int regions = 0;

    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            if (!vis[i][j] && grid[i][j] == '.') {
                regions++;

                top = 0;
                stack[top++] = (Node){i, j};
                vis[i][j] = 1;

                while (top > 0) {
                    Node cur = stack[--top];
                    for (int k = 0; k < 4; k++) {
                        int nr = cur.r + dr[k];
                        int nc = cur.c + dc[k];

                        if (nr >= 0 && nr < A &&
                            nc >= 0 && nc < B &&
                            !vis[nr][nc] &&
                            grid[nr][nc] == '.') 
                        {
                            vis[nr][nc] = 1;
                            stack[top++] = (Node){nr, nc};
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", regions);
    for (int i = 0; i < A; i++) {
        free(grid[i]);
        free(vis[i]);
    }
    free(grid);
    free(vis);
    free(stack);

    return 0;
}