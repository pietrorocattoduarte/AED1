#include <stdio.h>

int main() {
    int n;

    while (scanf("%d", &n) && n != 0) {
        int fila[1000];
        int tamanho = n;

        for (int i = 0; i < n; i++)
            fila[i] = i + 1;

        printf("Discarded cards:");
        int first = 1;

        while (tamanho > 1) {
            if (!first) printf(",");
            printf(" %d", fila[0]);
            first = 0;

            for (int i = 1; i < tamanho; i++)
                fila[i - 1] = fila[i];

            tamanho--;

            int temp = fila[0];
            for (int i = 1; i < tamanho; i++)
                fila[i - 1] = fila[i];
            fila[tamanho - 1] = temp;
        }

        printf("\nRemaining card: %d\n", fila[0]);
    }

    return 0;
}
