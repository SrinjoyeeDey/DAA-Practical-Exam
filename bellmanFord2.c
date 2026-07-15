#include<stdio.h>
#define INF 9999

int main(){
    FILE *fp=fopen("graph3.txt","r");
    if(fp==NULL){
        return 1;
    }
    int vertices,edges;
    fscanf(fp,"%d %d",&vertices,&edges);
    int u[edges],v[edges],wt[edges];

    for(int i=0;i<edges;i++){
        fscanf(fp,"%d %d %d",&u[i],&v[i],&wt[i]);
    }

    int dist[vertices];
    int source=0;

    for(int i=0;i<vertices;i++){
        dist[i]=INF;
    }
    dist[source]=0;

    for(int i=0;i<vertices;i++){
        for(int j=0;j<edges;j++){
            if(dist[u[j]]!=INF && dist[u[j]]+wt[j]<dist[v[j]]){
                dist[v[j]]=dist[u[j]]+wt[j];
            }
        }
    }
    for(int j=0;j<edges;j++){
            if(dist[u[j]]!=INF && dist[u[j]]+wt[j]<dist[v[j]]){
                printf("Negative Cycle exists!!");
                return 0;
            }
        }
    printf("Source\tDistance from Source\n");
    for(int i=0;i<vertices;i++){
        printf("%d\t%d\n",i,dist[i]);
    }
    return 0;
}