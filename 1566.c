#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int n;
        if (scanf("%d", &n) != 1) break;

        int *h = malloc(n * sizeof(int)); 
        if (!h) return 1; 

        for (int i = 0; i < n; i++) {
            if (scanf("%d", &h[i]) != 1) { 
                free(h);
                return 0;
            }
        }
        qsort(h, n, sizeof(int), compare);

        for (int i = 0; i < n; i++) {
            if (i) printf(" ");
            printf("%d", h[i]);
        }
        printf("\n");
        free(h); 
    }

    return 0;
}
