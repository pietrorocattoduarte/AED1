#include <stdio.h>

int adj[100][100];
int vis[100];
int V;
int cnt;

void dfs(int v){
    vis[v]=1;
    for(int i=0;i<V;i++){
        if(adj[v][i] && !vis[i]){
            cnt++;
            dfs(i);
        }
    }
}

int main(){
    int T;
    if(scanf("%d",&T)!=1) return 0;
    while(T--){
        int start,A,u,vv;
        scanf("%d %d %d",&start,&V,&A);
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(int j=0;j<V;j++) adj[i][j]=0;
        }
        for(int i=0;i<A;i++){
            scanf("%d %d",&u,&vv);
            adj[u][vv]=1;
            adj[vv][u]=1;
        }
        cnt=0;
        dfs(start);
        printf("%d\n",cnt*2);
    }
    return 0;
}
