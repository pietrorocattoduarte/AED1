#include <stdio.h>

int main() {
    int casos;
    scanf("%d", &casos);
    int sudoku[81];
    int *p = sudoku;
    for (int k = 1; k <= casos; k++) {
        for (int i = 0; i < 81; i++)
            scanf("%d", p + i);

        int valido = 1;

        for (int i = 0; i < 9 && valido; i++) {
            int check[10] = {0};
            for (int j = 0; j < 9; j++) {
                int num = *(p + i * 9 + j);
                if (num < 1 || num > 9 || check[num]) {
                    valido = 0;
                    break;
                }
                check[num] = 1;
            }
        }
        for (int j = 0; j < 9 && valido; j++) {
            int check[10] = {0};
            for (int i = 0; i < 9; i++) {
                int num = *(p + i * 9 + j);
                if (num < 1 || num > 9 || check[num]) {
                    valido = 0;
                    break;
                }
                check[num] = 1;
            }
        }
        for (int bi = 0; bi < 9 && valido; bi += 3) {
            for (int bj = 0; bj < 9 && valido; bj += 3) {
                int check[10] = {0};
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        int num = *(p + (bi + i) * 9 + (bj + j));
                        if (num < 1 || num > 9 || check[num]) {
                            valido = 0;
                            break;
                        }
                        check[num] = 1;
                    }
                }
            }
        }

        printf("Instancia %d\n", k);
        printf(valido ? "SIM\n\n" : "NAO\n\n");
    }

    return 0;
}