#include<stdio.h>
#define MAX 20
#define INF 9999

int main(){
    FILE *fp=fopen("graph1.txt","r");
    if(fp==NULL){
        printf("File not present!");
        return 1;
    }
    int V;
    fscanf(fp,"%d",&V);

    int graph[MAX][MAX];

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            fscanf(fp,"%d",&graph[i][j]);
        }
    }
    fclose(fp);

    int src;
    printf("Enter Source Vertex: ");
    scanf("%d",&src);

    int dist[MAX];
    int vis[MAX]={0};

    for(int i=0;i<V;i++){
        dist[i]=INF;
    }

    dist[src]=0;
    for(int count=0;count<V-1;count++){
        int min=INF;
        int u=-1;

        for(int i=0;i<V;i++){
            if(!vis[i] && dist[i]<min){
                min=dist[i];
                u=i;
            }
        }
        vis[u]=1;
        for(int v=0;v<V;v++){
            if(!vis[v] && graph[u][v]!=0 && dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    printf("Shortest distance\n");
    for(int i=0;i<V;i++){
        printf("%d - %d=%d\n",src,i,dist[i]);
    }

    return 0;
}