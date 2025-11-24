#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int M, C;
        scanf("%d %d", &M, &C);

        int hash[M][C]; 
        int count[M];

        for (int i = 0; i < M; i++)
            count[i] = 0;

        for (int i = 0; i < C; i++) {
            int x;
            scanf("%d", &x);
            int pos = x % M;
            hash[pos][count[pos]++] = x;
        }

        for (int i = 0; i < M; i++) {
            printf("%d ->", i);
            for (int j = 0; j < count[i]; j++)
                printf(" %d ->", hash[i][j]);
            printf(" \\\n");
        }

        if (T) printf("\n");
    }

    return 0;
}