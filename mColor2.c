#include<stdio.h>
#define V 4

int graph[V][V] = {
    {0,1,1,0},
    {1,0,1,1},
    {1,1,0,0},
    {0,1,0,0}
};

int color[V]={0};

int isSafe(int vertex,int c){
    for(int i=0;i<V;i++){
        if(graph[vertex][i]==1 && color[i]==c){
            return 0;
        }
    }
    return 1;
}

int solve(int vertex,int m){
    if(vertex==V){
        return 1;
    }
    for(int c=1;c<=m;c++){
        if(isSafe(vertex,c)){
            color[vertex]=c;
            if(solve(vertex+1,m)){
                return 1;
            }
            color[vertex]=0;
        }
    }
    return 0;
}

int main(){
    int m=5;
    if(solve(0,m)){
        printf("Vertex\tColor\n");
        for(int i=0;i<V;i++){
            printf("%d\t%d\n",i,color[i]);
        }
    }
    else{
        printf("Coloring not possible\n");
    }
    return 0;
}