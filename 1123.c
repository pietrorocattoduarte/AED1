#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 1000000000

typedef struct { int to, w; } Edge;

int main() {
    int n, m, c, k;
    while (1) {
        if (scanf("%d %d %d %d", &n, &m, &c, &k) != 4) return 0;
        if (n==0 && m==0 && c==0 && k==0) break;

        Edge **adj = malloc(n * sizeof(Edge*));
        int *deg = calloc(n, sizeof(int));
        for (int i=0;i<n;i++) adj[i]=NULL;

        int *routeW = malloc((n>0? n:1) * sizeof(int));
        for (int i=0;i<n;i++) routeW[i]=INF;

        for (int i=0;i<m;i++) {
            int a,b,w;
            scanf("%d %d %d", &a, &b, &w);
            if (a<0||a>=n||b<0||b>=n) continue;
            deg[a]++; adj[a] = realloc(adj[a], deg[a]*sizeof(Edge)); adj[a][deg[a]-1].to = b; adj[a][deg[a]-1].w = w;
            deg[b]++; adj[b] = realloc(adj[b], deg[b]*sizeof(Edge)); adj[b][deg[b]-1].to = a; adj[b][deg[b]-1].w = w;
            if (abs(a-b)==1) {
                int idx = a < b ? a : b;
                if (w < routeW[idx]) routeW[idx] = w;
            }
        }

        int *dist = malloc(n * sizeof(int));
        int *vis = calloc(n, sizeof(int));
        for (int i=0;i<n;i++) dist[i]=INF;
        dist[k]=0;

        for (int it=0; it<n; it++) {
            int u=-1, best=INF;
            for (int i=0;i<n;i++) if (!vis[i] && dist[i]<best) { best=dist[i]; u=i; }
            if (u==-1) break;
            vis[u]=1;
            if (u < c-1) {
                for (int j=0;j<deg[u];j++) {
                    int v = adj[u][j].to;
                    int w = adj[u][j].w;
                    if (v == u+1) {
                        if (dist[v] > dist[u] + w) dist[v] = dist[u] + w;
                    }
                }
            } else {
                for (int j=0;j<deg[u];j++) {
                    int v = adj[u][j].to;
                    int w = adj[u][j].w;
                    if (dist[v] > dist[u] + w) dist[v] = dist[u] + w;
                }
            }
        }

        for (int i=0;i<c-1;i++) {
            if (dist[i] < INF && routeW[i] < INF) {
                if (dist[i+1] > dist[i] + routeW[i]) dist[i+1] = dist[i] + routeW[i];
            }
        }

        if (dist[c-1] >= INF) printf("-1\n");
        else printf("%d\n", dist[c-1]);

        for (int i=0;i<n;i++) free(adj[i]);
        free(adj); free(deg); free(dist); free(vis); free(routeW);
    }
    return 0;
}
