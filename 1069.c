#include <stdio.h>

int main() {
    int T;
    char s[1001];

    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);

        int aberto = 0; 
        int diamantes = 0;

        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '<') {
                aberto++;  
            } else if (s[i] == '>' && aberto > 0) {
                diamantes++; 
                aberto--; 
            }
        }

        printf("%d\n", diamantes);
    }

    return 0;
}