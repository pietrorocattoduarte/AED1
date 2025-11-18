#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int v;
    struct No *e, *d;
} No;

No* novo(int v) {
    No *n = malloc(sizeof(No));
    n->v = v;
    n->e = n->d = NULL;
    return n;
}

No* insere(No *r, int v) {
    if (!r) return novo(v);
    if (v < r->v) r->e = insere(r->e, v);
    else r->d = insere(r->d, v);
    return r;
}

void pre(No *r) {
    if (!r) return;
    printf("%d", r->v);
    if (r->e) printf(" "), pre(r->e);
    if (r->d) printf(" "), pre(r->d);
}

void in(No *r) {
    if (!r) return;
    if (r->e) in(r->e), printf(" ");
    printf("%d", r->v);
    if (r->d) printf(" "), in(r->d);
}

void pos(No *r) {
    if (!r) return;
    if (r->e) pos(r->e), printf(" ");
    if (r->d) pos(r->d), printf(" ");
    printf("%d", r->v);
}

void libera(No *r) {
    if (!r) return;
    libera(r->e);
    libera(r->d);
    free(r);
}

int main() {
    int c, n, v;
    scanf("%d", &c);
    for (int k = 1; k <= c; k++) {
        scanf("%d", &n);
        No *r = NULL;
        for (int i = 0; i < n; i++) {
            scanf("%d", &v);
            r = insere(r, v);
        }
        printf("Case %d:\n", k);
        printf("Pre.: "); pre(r); printf("\n");
        printf("In..: "); in(r);  printf("\n");
        printf("Post: "); pos(r); printf("\n\n");
        libera(r);
    }
}
