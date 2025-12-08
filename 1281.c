#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char nome[50];
    double preco;
    struct No *prox;
} No;

void inserir(No **lista, char *nome, double preco) {
    No *novo = malloc(sizeof(No));
    strcpy(novo->nome, nome);
    novo->preco = preco;
    novo->prox = *lista;
    *lista = novo;
}

double buscarPreco(No *lista, char *nome) {
    while (lista) {
        if (strcmp(lista->nome, nome) == 0)
            return lista->preco;
        lista = lista->prox;
    }
    return 0.0;
}

void liberar(No **lista) {
    while (*lista) {
        No *tmp = (*lista)->prox;
        free(*lista);
        *lista = tmp;
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        No *lista = NULL;
        int N, M, qtd;
        char nome[50];
        double preco, total = 0;

        scanf("%d", &N);
        while (N--) {
            scanf("%s %lf", nome, &preco);
            inserir(&lista, nome, preco);
        }

        scanf("%d", &M);
        while (M--) {
            scanf("%s %d", nome, &qtd);
            total += buscarPreco(lista, nome) * qtd;
        }

        printf("R$ %.2lf\n", total);
        liberar(&lista);
    }

    return 0;
}
