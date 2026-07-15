#include<stdio.h>
#define MAX 20
#define INF 9999

int main(){
    FILE *fp=fopen("graph1.txt","r");
    if(fp==NULL){
        return 1;
    }
    int graph[MAX][MAX];
    int vertices;
    fscanf(fp,"%d",&vertices);

    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            fscanf(fp,"%d",&graph[i][j]);
        }
    }

    for(int k=0;k<vertices;k++){
        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++){
                if(graph[i][k]+graph[k][j]<graph[i][j]){
                    graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
    }

    printf("Shortest distance: \n");
    for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++){
                if(graph[i][j]==INF) printf("INF ");
                else
                    printf("%3d",graph[i][j]);
            }
            printf("\n");
        }
    return 0;
}