#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
    int id[] = {1,2,3,4,5};
    int deadline[] = {2,1,2,1,3};
    int profit[] = {100,19,27,25,15};
    int n=5;

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(profit[i]<profit[j]){
                swap(&profit[i],&profit[j]);
                swap(&deadline[i],&deadline[j]);
                swap(&id[i],&id[j]);
            }
        }
    }
    int maxDeadline=deadline[0];
    for(int i=1;i<n;i++){
        if(deadline[i]>maxDeadline){
            maxDeadline=deadline[i];
        }
    }

    int slot[maxDeadline];
    int maxprofit=0;

    for(int i=0;i<maxDeadline;i++){
        slot[i]=-1;
    }

    for(int i=0;i<n;i++){
        for(int j=deadline[i]-1;j>=0;j--){
            if(slot[j]==-1){
                slot[j]=id[i];
                maxprofit+=profit[i];
                break;
            }
        }
    }

    for(int i=0;i<maxDeadline;i++){
        if(slot[i]!=-1)
            printf("JD%d ",slot[i]);
    }
    printf("\nMaximum Profit: %d\n",maxprofit);
}