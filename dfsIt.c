#include<stdio.h>
#define V 5

int main(){
    int graph[V][V] = {
        {0,1,1,0,0},
        {1,0,1,1,0},
        {1,1,0,0,1},
        {0,1,0,0,1},
        {0,0,1,1,0}
    };
    int stack[V];
    int start=0;
    int top=-1;
    stack[++top]=start;
    int vis[V]={0};
    vis[start]=1;

    printf("DFS Traversal: \n");
    while (top!=-1)
    {
        int curr=stack[top--];
        printf("%3d",curr);

        for(int i=V-1;i>=0;i--){
            if(!vis[i] && graph[curr][i]==1){
                stack[++top]=i;
                vis[i]=1;
            }
        }
    }
    return 0;
    
}