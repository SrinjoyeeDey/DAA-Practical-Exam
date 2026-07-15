#include<stdio.h>

int find(int par[],int vertex){
    while(par[vertex]!=vertex){
        vertex=par[vertex];
    }
    return vertex;
}

int main(){
    FILE *fp=fopen("file.txt","r");
    if(fp==NULL){
        return 1;
    }
    int vertices,edges;
    fscanf(fp,"%d %d",&vertices,&edges);

    int u[edges],v[edges],wt[edges];
    for(int i=0;i<edges;i++){
        fscanf(fp,"%d %d %d",&u[i],&v[i],&wt[i]);
    }
    fclose(fp);

    for(int i=0;i<edges-1;i++){
      for(int j=i+1;j<edges;j++){
            if(wt[i]>wt[j]){
                int tempWt=wt[i];
                wt[i]=wt[j];
                wt[j]=tempWt;

                int tempV=v[i];
                v[i]=v[j];
                v[j]=tempV;

                int tempU=u[i];
                u[i]=u[j];
                u[j]=tempU;
            }
        }  
    }
    int par[vertices];
    int cost=0;
    for(int i=0;i<vertices;i++){
        par[i]=i;
    }
    for(int i=0;i<edges;i++){
        int p1=find(par,u[i]);
        int p2=find(par,v[i]);

        if(p1!=p2){
            printf("%d - %d , Weight: %d\n",u[i],v[i],wt[i]);
            cost+=wt[i];
            par[p1]=p2;
        }
    }

    printf("Minimum Cost: %d",cost);
    return 0;
}