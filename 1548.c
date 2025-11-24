#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        int original[N], ordenado[N];

        for (int i = 0; i < N; i++) {
            scanf("%d", &original[i]);
            ordenado[i] = original[i];
        }

        qsort(ordenado, N, sizeof(int), cmp);

        int cont = 0;
        for (int i = 0; i < N; i++) {
            if (original[i] == ordenado[i])
                cont++;
        }

        printf("%d\n", cont);
    }

    return 0;
}