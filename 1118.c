#include <stdio.h>

#define MAX 2

typedef struct {
    double dados[MAX];
    int topo;
} Pilha;

void push(Pilha *p, double x) {
    if (p->topo < MAX) p->dados[p->topo++] = x;
}

double pop(Pilha *p) {
    return p->dados[--p->topo];
}

int main() {
    Pilha p;
    int opc;
    double nota;

    while (1) {
        p.topo = 0;

        while (p.topo < 2) {
            scanf("%lf", &nota);

            if (nota < 0 || nota > 10) {
                printf("nota invalida\n");
            } else {
                push(&p, nota);
            }
        }

        double n2 = pop(&p);
        double n1 = pop(&p);

        printf("media = %.2lf\n", (n1 + n2) / 2);

        do {
            printf("novo calculo (1-sim 2-nao)\n");
            scanf("%d", &opc);
        } while (opc != 1 && opc != 2);

        if (opc == 2) break;
    }

    return 0;
}
