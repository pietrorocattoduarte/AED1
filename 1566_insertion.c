#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int n;
        if (scanf("%d", &n) != 1) break;

        int *h = malloc(n * sizeof(int)); 
        if (!h) return 1;

        for (int i = 0; i < n; i++)
            if (scanf("%d", &h[i]) != 1) { free(h); return 0; }

        for (int i = 1; i < n; i++) {
            int chave = h[i];
            int j = i - 1;

            while (j >= 0 && h[j] > chave) {
                h[j + 1] = h[j];
                j--;
            }
            h[j + 1] = chave;
        }

        for (int i = 0; i < n; i++) {
            if (i) printf(" ");
            printf("%d", h[i]);
        }
        printf("\n");

        free(h);
    }

    return 0;
}
