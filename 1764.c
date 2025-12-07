#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int u, v, w;
} Aresta;

int cmp(const void *a, const void *b){
    return ((Aresta*)a)->w - ((Aresta*)b)->w;
}

int find(int *pai, int x){
    if(pai[x] == x) return x;
    return pai[x] = find(pai, pai[x]);
}

void unite(int *pai, int *rank, int a, int b){
    a = find(pai, a);
    b = find(pai, b);
    if(a != b){
        if(rank[a] < rank[b]) pai[a] = b;
        else if(rank[a] > rank[b]) pai[b] = a;
        else{
            pai[b] = a;
            rank[a]++;
        }
    }
}

int main(){
    int n, m;

    while(1){
        if(scanf("%d %d", &n, &m) != 2) return 0;
        if(n == 0 && m == 0) break;

        Aresta *arestas = malloc(m * sizeof(Aresta));

        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].w);
        }

        qsort(arestas, m, sizeof(Aresta), cmp);

        int *pai = malloc(n * sizeof(int));
        int *rank = malloc(n * sizeof(int));

        for(int i = 0; i < n; i++){
            pai[i] = i;
            rank[i] = 0;
        }

        int custo = 0, usado = 0;

        for(int i = 0; i < m && usado < n - 1; i++){
            if(find(pai, arestas[i].u) != find(pai, arestas[i].v)){
                unite(pai, rank, arestas[i].u, arestas[i].v);
                custo += arestas[i].w;
                usado++;
            }
        }

        printf("%d\n", custo);

        free(arestas);
        free(pai);
        free(rank);
    }

    return 0;
}
