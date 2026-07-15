#include<stdio.h>
#define V 5
#define INF 9999

int main(){
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int vis[V]={0};
    vis[0]=1;
    int edgeCount=0;
    int cost=0;

    while (edgeCount<V-1)
    {
        int min=INF;
        int u=-1;
        int v=-1;
        for(int i=0;i<V;i++){
            if(vis[i]!=0){
                for(int j=0;j<V;j++){
                    if(vis[j]==0 && graph[i][j]!=0){
                        if(graph[i][j]<min){
                            min=graph[i][j];
                            u=i;
                            v=j;
                        }
                    }
                }
            }
        }
        cost+=min;
        printf("%d - %d, weight: %d\n",u,v,min);
        vis[v]=1;
        edgeCount++;
    }
     printf("Minimum Cost = %d\n", cost);
     return 0;
}