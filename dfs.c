#include<stdio.h>
#define V 6

void dfs(int adj[V][V],int vis[],int vertex){

    vis[vertex]=1;
    printf("%d ",vertex);
    
    for(int i=0;i<V;i++){
        if(vis[i]==0 &&adj[vertex][i]==1){
            dfs(adj,vis,i);
        }
    }
}
int main(){
    int adj[V][V] = {
        {0,1,1,1,0,0}, //0
        {1,0,0,0,1,1}, //1
        {1,0,0,0,0,0}, //2
        {1,0,0,0,0,1}, //3
        {0,1,0,0,0,0}, //4
        {0,1,0,1,0,0}  //5
    };
    int vis[V]={0};

    printf("DFS Traversal: ");
    dfs(adj,vis,0);
    return 0;
}