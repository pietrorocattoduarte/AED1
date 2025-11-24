#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int *fila = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &fila[i]);
    }

    int M;
    scanf("%d", &M);
    int maxId = 100000 + 5;
    char *saiu = calloc(maxId, sizeof(char));

    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        saiu[x] = 1;
    }
    int first = 1;
    for (int i = 0; i < N; i++) {
        int id = fila[i];
        if (!saiu[id]) {
            if (!first) printf(" ");
            printf("%d", id);
            first = 0;
        }
    }
    printf("\n");

    free(fila);
    free(saiu);
    return 0;
}