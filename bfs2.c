#include<stdio.h>
#define MAX 20

void bfs(int adj[MAX][MAX],int V,int i){
    int vis[MAX]={0};
    int queue[MAX];
    int front=0;
    int rear=0;

    vis[i]=1;
    queue[rear++]=i;

    while (front<rear)
    {
        int curr=queue[front++];
        printf("%3d",curr);

        for(int j=0;j<V;j++){
            if(adj[curr][j]==1 && vis[j]==0){
                vis[j]=1;
                queue[rear++]=j;
            }
        }
    }
}

int main(){
    int adj[MAX][MAX];
    int vis[MAX]={0};

    FILE *fp=fopen("graph4.txt","r");
    if(fp==NULL){
        printf("File don't exist!");
        return 1;
    }

    int V;
    fscanf(fp,"%d",&V);

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            fscanf(fp,"%d",&adj[i][j]);
        }
    }
    fclose(fp);

    printf("BFS Traversal: \n");
    bfs(adj,V,0);
    return 0;
}