#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int v;
    struct Node *next;
} Node;

Node *adj[10001];
int vis[10001];
int pilha[10001];

int n, m;

int dfs(int start){
    int stack[10001], top = 0;
    stack[top++] = start;

    while(top){
        int u = stack[top-1];
        if(!vis[u]){
            vis[u] = 1;
            pilha[u] = 1;
        }

        Node *cur = adj[u];
        int found = 0;

        while(cur){
            int v = cur->v;
            if(!vis[v]){
                stack[top++] = v;
                found = 1;
                break;
            }
            else if(pilha[v]){
                return 1;
            }
            cur = cur->next;
        }

        if(!found){
            pilha[u] = 0;
            top--;
        }
    }

    return 0;
}

void add_edge(int u, int v){
    Node *novo = malloc(sizeof(Node));
    novo->v = v;
    novo->next = adj[u];
    adj[u] = novo;
}

void free_graph(){
    for(int i=1;i<=n;i++){
        Node *cur = adj[i];
        while(cur){
            Node *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
        adj[i] = NULL;
    }
}

int main(){
    int t;
    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) adj[i]=NULL;
        for(int i=1;i<=n;i++) vis[i]=0, pilha[i]=0;

        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            add_edge(a,b);
        }

        int ciclo = 0;
        for(int i=1;i<=n && !ciclo;i++){
            if(!vis[i] && dfs(i)) ciclo=1;
        }

        if(ciclo) printf("SIM\n");
        else printf("NAO\n");

        free_graph();
    }

    return 0;
}
