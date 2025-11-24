#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct {
    int u, v;
    int w;
} Edge;

int cmpEdge(const void *a, const void *b) {
    Edge *ea = (Edge*)a;
    Edge *eb = (Edge*)b;
    if (ea->w < eb->w) return -1;
    if (ea->w > eb->w) return 1;
    return 0;
}
typedef struct {
    int *parent;
    int *rank;
    int n;
} DSU;

DSU *dsu_create(int n) {
    DSU *d = (DSU*)malloc(sizeof(DSU));
    d->n = n;
    d->parent = (int*)malloc(sizeof(int)*n);
    d->rank = (int*)malloc(sizeof(int)*n);
    for (int i=0;i<n;i++){ d->parent[i]=i; d->rank[i]=0; }
    return d;
}

int dsu_find(DSU *d, int x) {
    if (d->parent[x] != x) d->parent[x] = dsu_find(d, d->parent[x]);
    return d->parent[x];
}

void dsu_union(DSU *d, int x, int y) {
    int rx = dsu_find(d, x);
    int ry = dsu_find(d, y);
    if (rx == ry) return;
    if (d->rank[rx] < d->rank[ry]) d->parent[rx] = ry;
    else if (d->rank[ry] < d->rank[rx]) d->parent[ry] = rx;
    else { d->parent[ry] = rx; d->rank[rx]++; }
}

void dsu_free(DSU *d) {
    free(d->parent);
    free(d->rank);
    free(d);
}

int main() {
    int M, N;
    while (scanf("%d %d", &M, &N) == 2) {
        if (M == 0 && N == 0) break;

        Edge *edges = (Edge*)malloc(sizeof(Edge)*N);
        for (int i = 0; i < N; ++i) {
            int x,y,w;
            scanf("%d %d %d", &x, &y, &w);
            edges[i].u = x;
            edges[i].v = y;
            edges[i].w = w;
        }

        qsort(edges, N, sizeof(Edge), cmpEdge);

        DSU *d = dsu_create(M);
        ll total = 0;
        int taken = 0;

        for (int i = 0; i < N && taken < M-1; ++i) {
            int ru = dsu_find(d, edges[i].u);
            int rv = dsu_find(d, edges[i].v);
            if (ru != rv) {
                dsu_union(d, ru, rv);
                total += edges[i].w;
                taken++;
            }
        }

        printf("%lld\n", total);

        dsu_free(d);
        free(edges);
    }
    return 0;
}