#include <stdio.h>
#include <string.h>
#define expressao 1000
int main() {
    char N[expressao];
    
    while (scanf("%s", N) != EOF) {
        char pilha[expressao];
        int indice_topo = -1;

        for (int indice = 0; indice < strlen(N); indice++) {
            if (N[indice] == '(') {
                indice_topo++;
                pilha[indice_topo] = '(';
            } 
            else if (N[indice] == ')') {
                if (indice_topo == -1) {
                    indice_topo = -2;
                    break;
                } 
                else {
                    indice_topo--;
                }
            }
        }
        
        if (indice_topo == -1)
            printf("correct\n");
        else
            printf("incorrect\n");
    }

    return 0;
}