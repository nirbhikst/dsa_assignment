// prog_7.c
#include <stdio.h>
#include <limits.h>

#define MAXV 50
#define INF  1000000000

int min_dist(int n, int dist[], int used[]){
    int best=-1;
    for(int i=0;i<n;i++){
        if(!used[i] && (best==-1 || dist[i]<dist[best])) best=i;
    }
    return best;
}

void dijkstra(int n, int w[MAXV][MAXV], int src){
    int dist[MAXV], used[MAXV]={0};
    for(int i=0;i<n;i++) dist[i]=INF;
    dist[src]=0;

    for(int it=0; it<n; it++){
        int u=min_dist(n,dist,used);
        if(u==-1 || dist[u]==INF) break;
        used[u]=1;

        for(int v=0; v<n; v++){
            if(w[u][v]>0 && !used[v]){
                if(dist[u] + w[u][v] < dist[v]){
                    dist[v] = dist[u] + w[u][v];
                }
            }
        }
    }

    printf("Shortest distances from %d:\n", src);
    for(int i=0;i<n;i++){
        if(dist[i]==INF) printf("%d -> %d : INF\n", src, i);
        else printf("%d -> %d : %d\n", src, i, dist[i]);
    }
}

int main(){
    int n=5;
    int w[MAXV][MAXV]={0};

    // example weighted undirected edges
    w[0][1]=w[1][0]=4;
    w[0][2]=w[2][0]=1;
    w[2][1]=w[1][2]=2;
    w[1][3]=w[3][1]=1;
    w[2][3]=w[3][2]=5;
    w[3][4]=w[4][3]=3;

    dijkstra(n,w,0);
    return 0;
}
