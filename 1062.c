#include <stdio.h>
#define MAX 1000

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        while (1) {
            int alvo[MAX];
            if (scanf("%d", &alvo[0]), alvo[0] == 0) { 
                printf("\n"); 
                break; 
            }

            for (int i = 1; i < n; i++) scanf("%d", &alvo[i]);

            int pilha[MAX], topo = -1, proximo = 1, ok = 1;
            for (int i = 0; i < n; i++) {
                while (proximo <= n && (topo == -1 || pilha[topo] != alvo[i]))
                    pilha[++topo] = proximo++;
                if (pilha[topo] == alvo[i]) topo--;
                else { ok = 0; break; }
            }
            printf(ok ? "Yes\n" : "No\n");
        }
    }
    return 0;
}
