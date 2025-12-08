#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char dado;
    struct No *esq, *dir;
} No;

No* novoNo(char c) {
    No* n = (No*) malloc(sizeof(No));
    n->dado = c;
    n->esq = n->dir = NULL;
    return n;
}

No* inserir(No* r, char c) {
    if (r == NULL)
        return novoNo(c);
    if (c < r->dado)
        r->esq = inserir(r->esq, c);
    else if (c > r->dado)
        r->dir = inserir(r->dir, c);
    return r;
}

int buscar(No* r, char c) {
    if (!r) return 0;
    if (c == r->dado) return 1;
    if (c < r->dado) return buscar(r->esq, c);
    return buscar(r->dir, c);
}

No* menor(No* r) {
    while (r->esq) r = r->esq;
    return r;
}

No* remover(No* r, char c) {
    if (!r) return NULL;
    if (c < r->dado) {
        r->esq = remover(r->esq, c);
    } else if (c > r->dado) {
        r->dir = remover(r->dir, c);
    } else {
        if (!r->esq && !r->dir) {
            free(r);
            return NULL;
        }
        if (!r->esq) {
            No* tmp = r->dir;
            free(r);
            return tmp;
        }
        if (!r->dir) {
            No* tmp = r->esq;
            free(r);
            return tmp;
        }
        No* suc = menor(r->dir);
        r->dado = suc->dado;
        r->dir = remover(r->dir, suc->dado);
    }
    return r;
}

int fill_prefix(No* r, char arr[], int idx) {
    if (!r) return idx;
    arr[idx++] = r->dado;
    idx = fill_prefix(r->esq, arr, idx);
    idx = fill_prefix(r->dir, arr, idx);
    return idx;
}

int fill_infix(No* r, char arr[], int idx) {
    if (!r) return idx;
    idx = fill_infix(r->esq, arr, idx);
    arr[idx++] = r->dado;
    idx = fill_infix(r->dir, arr, idx);
    return idx;
}

int fill_posfix(No* r, char arr[], int idx) {
    if (!r) return idx;
    idx = fill_posfix(r->esq, arr, idx);
    idx = fill_posfix(r->dir, arr, idx);
    arr[idx++] = r->dado;
    return idx;
}

void imprimir_array(char arr[], int n) {
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%c", arr[i]);
    }
    printf("\n");
}

void libera(No **r) {
    if (!*r) return;
    libera(&(*r)->esq);
    libera(&(*r)->dir);
    free(*r);
    *r = NULL;
}

int main() {
    No* raiz = NULL;
    char op[30];
    char c;

    while (scanf("%s", op) != EOF) {
        if (strcmp(op, "I") == 0) {
            scanf(" %c", &c);
            raiz = inserir(raiz, c);
        } 
        else if (strcmp(op, "P") == 0) {
            scanf(" %c", &c);
            if (buscar(raiz, c))
                printf("%c existe\n", c);
            else
                printf("%c nao existe\n", c);
        } 
        else if (strcmp(op, "R") == 0) {
            scanf(" %c", &c);
            raiz = remover(raiz, c);
        } 
        else if (strcmp(op, "PREFIXA") == 0) {
            char arr[1000];
            int n = fill_prefix(raiz, arr, 0);
            imprimir_array(arr, n);
        } 
        else if (strcmp(op, "INFIXA") == 0) {
            char arr[1000];
            int n = fill_infix(raiz, arr, 0);
            imprimir_array(arr, n);
        } 
        else if (strcmp(op, "POSFIXA") == 0) {
            char arr[1000];
            int n = fill_posfix(raiz, arr, 0);
            imprimir_array(arr, n);
        }
    }

    libera(&raiz);
    return 0;
}
