#include<stdio.h>
#define MAX 20

void dfs(int adj[MAX][MAX],int vis[],int V,int i){
    vis[i]=1;
    printf("%3d",i);

    for(int j=0;j<V;j++){
        if(vis[j]==0 && adj[i][j]==1){
            dfs(adj,vis,V,j);
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

    printf("DFS Traversal: \n");
    dfs(adj,vis,V,0);
    return 0;
}