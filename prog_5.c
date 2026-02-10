// prog_5.c
#include <stdio.h>

#define MAXV 50

void bfs(int n, int g[MAXV][MAXV], int start){
    int q[MAXV], front=0, rear=0;
    int vis[MAXV]={0};

    vis[start]=1;
    q[rear++]=start;

    printf("BFS: ");
    while(front<rear){
        int u=q[front++];
        printf("%d ", u);
        for(int v=0; v<n; v++){
            if(g[u][v] && !vis[v]){
                vis[v]=1;
                q[rear++]=v;
            }
        }
    }
    printf("\n");
}

void dfs_rec(int n, int g[MAXV][MAXV], int u, int vis[MAXV]){
    vis[u]=1;
    printf("%d ", u);
    for(int v=0; v<n; v++){
        if(g[u][v] && !vis[v]) dfs_rec(n,g,v,vis);
    }
}

void dfs(int n, int g[MAXV][MAXV], int start){
    int vis[MAXV]={0};
    printf("DFS: ");
    dfs_rec(n,g,start,vis);
    printf("\n");
}

int main(){
    int n=6;
    int g[MAXV][MAXV]={0};

    // example undirected edges
    int edges[][2]={{0,1},{0,2},{1,3},{1,4},{2,4},{3,5},{4,5}};
    int m=7;

    for(int i=0;i<m;i++){
        int u=edges[i][0], v=edges[i][1];
        g[u][v]=g[v][u]=1;
    }

    bfs(n,g,0);
    dfs(n,g,0);
    return 0;
}
