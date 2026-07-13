#include<stdio.h>
#define V 6

void bfs(int adj[V][V],int vertex){
    int front=0,rear=0;
    int queue[V];
    int vis[V]={0};

    vis[vertex]=1;
    queue[rear++]=vertex;

    while (front<rear)
    {
        int curr=queue[front++];
        printf("%d ",curr);
        for(int i=0;i<V;i++){
            if(adj[curr][i]==1 && vis[i]==0){
                vis[i]=1;
                queue[rear++]=i;
            }
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

    printf("BFS Traversal: ");
    bfs(adj,0);
    return 0;
}