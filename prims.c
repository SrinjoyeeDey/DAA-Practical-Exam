#include<stdio.h>
#define MAX 20
#define INF 9999

int main(){
    FILE *fp=fopen("graph.txt","r");
    if(fp==NULL){
        printf("File doesn't exist");
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

    int vis[MAX]={0};
    vis[0]=1;

    int edgeCount=0;
    int cost=0;
    printf("Edges are: ");

    while (edgeCount<V-1)
    {
        int min=INF;
        int u=-1,v=-1;

        for(int i=0;i<V;i++){
            if(vis[i]!=0){
                for(int j=0;j<V;j++){
                    if(!vis[j] && graph[i][j]!=0){
                        if(graph[i][j]<min){
                            min=graph[i][j];
                            u=i;
                            v=j;
                        }
                    }
                }
            }
        }
        printf("%d - %d: %d\n",u,v,min);
        cost+=min;
        vis[v]=1;
        edgeCount++;
    }
    printf("Minimum Cost: %d",cost);
    return 0;

}