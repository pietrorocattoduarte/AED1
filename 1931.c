#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long long ll;
const ll INF = (1LL<<60);

int N, M;
int maxE;

int *head;
int *to;
int *w;
int *nxt;
int ec;

void add_edge_int(int u,int v,int wt){
    to[ec]=v;
    w[ec]=wt;
    nxt[ec]=head[u];
    head[u]=ec++;
}

typedef struct{ ll d; int v; } Item;
Item *pq;
int psz;

void pq_push(ll d,int v){
    int i = ++psz;
    pq[i].d = d; pq[i].v = v;
    while(i>1){
        int p = i/2;
        if(pq[p].d <= pq[i].d) break;
        Item tmp = pq[p]; pq[p]=pq[i]; pq[i]=tmp;
        i = p;
    }
}

Item pq_pop(){
    Item res = pq[1];
    pq[1] = pq[psz--];
    int i = 1;
    while(1){
        int l = 2*i, r = l+1, smallest = i;
        if(l<=psz && pq[l].d < pq[smallest].d) smallest = l;
        if(r<=psz && pq[r].d < pq[smallest].d) smallest = r;
        if(smallest==i) break;
        Item tmp = pq[i]; pq[i]=pq[smallest]; pq[smallest]=tmp;
        i = smallest;
    }
    return res;
}

int main(){
    if(scanf("%d %d",&N,&M)!=2) return 0;
    int nodes = 2 * N;
    maxE = 4 * M + 5;
    head = malloc(sizeof(int)*nodes);
    to   = malloc(sizeof(int)*maxE);
    w    = malloc(sizeof(int)*maxE);
    nxt  = malloc(sizeof(int)*maxE);
    for(int i=0;i<nodes;i++) head[i]=-1;
    ec=0;
    for(int i=0;i<M;i++){
        int a,b,wt;
        scanf("%d %d %d",&a,&b,&wt);
        int a0 = (0)*N + (a-1);
        int a1 = (1)*N + (a-1);
        int b0 = (0)*N + (b-1);
        int b1 = (1)*N + (b-1);
        add_edge_int(a0,b1,wt);
        add_edge_int(b0,a1,wt);
        add_edge_int(a1,b0,wt);
        add_edge_int(b1,a0,wt);
    }
    ll *dist = malloc(sizeof(ll)*nodes);
    int *vis = malloc(sizeof(int)*nodes);
    for(int i=0;i<nodes;i++){ dist[i]=INF; vis[i]=0; }
    int start = 0*N + (1-1);
    int target = 0*N + (N-1);
    dist[start]=0;
    pq = malloc(sizeof(Item)*(nodes*20+10));
    psz=0;
    pq_push(0,start);
    while(psz>0){
        Item it = pq_pop();
        ll d = it.d; int v = it.v;
        if(d!=dist[v]) continue;
        if(v==target) break;
        for(int e=head[v]; e!=-1; e=nxt[e]){
            int u = to[e];
            ll nd = d + (ll)w[e];
            if(nd < dist[u]){
                dist[u]=nd;
                pq_push(nd,u);
            }
        }
    }
    if(dist[target]>=INF) printf("-1\n");
    else printf("%lld\n", dist[target]);
    return 0;
}
