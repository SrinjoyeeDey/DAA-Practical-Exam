#include<stdio.h>
#define MAX 20
#define INF 9999

int main(){
    FILE *fp=fopen("graph1.txt","r");

    if(fp==NULL){
        printf("File not present!");
        return 1;
    }

    int graph[MAX][MAX];
    int V;
    fscanf(fp,"%d",&V);

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            fscanf(fp,"%d",&graph[i][j]);
        }
    }
    fclose(fp);

    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(graph[i][k]+graph[k][j]<graph[i][j]){
                    graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
    }

    printf("Shortest distance Matrix: ");
    for(int i=0;i<V;i++){
       for(int j=0;j<V;j++){
            if(graph[i][j]==INF){
                printf("INF");
            }
            else{
                printf("%3d",graph[i][j]);
            }
        } 
        printf("\n");
    }
    return 0;
}