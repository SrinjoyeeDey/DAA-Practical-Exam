#include<stdio.h>

int find(int par[],int vertex){
    if(par[vertex]!=vertex){
        vertex=par[vertex];
    }
    return vertex;
}
int main(){
    FILE *fp;
    fp=fopen("file.txt","r");

    if(fp==NULL){
        printf("File Not Found!");
        return 0;
    }
    int vertex,edges;
    fscanf(fp,"%d %d",&vertex,&edges);
    int u[edges],v[edges],wt[edges];

    for(int i=0;i<edges;i++){
        fscanf(fp,"%d %d %d",&u[i],&v[i],&wt[i]);
    }
    fclose(fp);

    for(int i=0;i<edges-1;i++){
        for(int j=i+1;j<edges;j++){
            if(wt[i]>wt[j]){
                int temp;

                temp=wt[i];
                wt[i]=wt[j];
                wt[j]=temp;

                temp=u[i];
                u[i]=u[j];
                u[j]=temp;

                temp=v[i];
                v[i]=v[j];
                v[j]=temp;
            }
        }
    }

    int par[vertex];
    for(int i=0;i<vertex;i++){
        par[i]=i;
    }
    int cost=0;
    printf("Edges in MST: ");

    for(int i=0;i<edges;i++){
        int p1=find(par,u[i]);
        int p2=find(par,v[i]);

        if(p1!=p2){
            printf("%d - %d Weight =%d\n",u[i],v[i],wt[i]);
            cost+=wt[i];
            par[p1]=p2;
        }
    }

    printf("Minimum Cost=%d", cost);
    return 0;
}