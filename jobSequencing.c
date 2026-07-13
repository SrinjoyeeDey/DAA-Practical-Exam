#include<stdio.h>

int main(){
    int id[] = {1,2,3,4,5};
    int deadline[] = {2,1,2,1,3};
    int profit[] = {100,19,27,25,15};
    int n=5;

    int maxProfit=0;

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(profit[i]<profit[j]){
                int tempProfit=profit[i];
                profit[i]=profit[j];
                profit[j]=tempProfit;

                int tempdeadline=deadline[i];
                deadline[i]=deadline[j];
                deadline[j]=tempdeadline;

                int tempid=id[i];
                id[i]=id[j];
                id[j]=tempid;
            }
        }
    }

    int maxDeadline=deadline[0];
    for(int i=1;i<n;i++){
        if(deadline[i]>maxDeadline) maxDeadline=deadline[i];
    }
    int slot[maxDeadline];

    for(int i=0;i<maxDeadline;i++){
        slot[i]=-1;
    }

    for(int i=0;i<n;i++){
        for(int j=deadline[i]-1;j>=0;j--){
            if(slot[j]==-1){
                slot[j]=id[i];
                maxProfit+=profit[i];
                break;
            }
        }
    }

    for(int i=0;i<maxDeadline;i++){
        if(slot[i]!=-1){
            printf("JD%d ",slot[i]);
        }
    }
    printf("Maximum profit: %d\n",maxProfit);
    return 0;
}