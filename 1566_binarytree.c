#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int v;
    int freq;
    struct No *e, *d;
} No;

No* novo(int v) {
    No *n = malloc(sizeof(No));
    n->v = v;
    n->freq = 1;
    n->e = n->d = NULL;
    return n;
}

No* insere(No *r, int v) {
    if (!r) return novo(v);
    if (v < r->v) r->e = insere(r->e, v);
    else if (v > r->v) r->d = insere(r->d, v);
    else r->freq++;
    return r;
}

void emOrdem(No *r) {
    if (!r) return;
    emOrdem(r->e);
    for (int i = 0; i < r->freq; i++) {
        printf("%d", r->v);
        if (!(r->e == NULL && r->d == NULL && i == r->freq - 1))
            printf(" ");
    }
    if (r->d) printf(" ");
    emOrdem(r->d);
}

void emOrdemSemEspaco(No *r, int *primeiro) {
    if (!r) return;
    emOrdemSemEspaco(r->e, primeiro);
    for (int i = 0; i < r->freq; i++) {
        if (!*primeiro) printf(" ");
        printf("%d", r->v);
        *primeiro = 0;
    }
    emOrdemSemEspaco(r->d, primeiro);
}

void libera(No *r) {
    if (!r) return;
    libera(r->e);
    libera(r->d);
    free(r);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, v;
        scanf("%d", &N);
        No *r = NULL;
        for (int i = 0; i < N; i++) {
            scanf("%d", &v);
            r = insere(r, v);
        }
        int primeiro = 1;
        emOrdemSemEspaco(r, &primeiro);
        printf("\n");
        libera(r);
    }
    return 0;
}
