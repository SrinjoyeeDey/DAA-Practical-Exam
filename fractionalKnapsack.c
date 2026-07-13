#include<stdio.h>

int main(){
    int wt[]={10, 20, 30};
    int profit[]={60, 100, 120};
    int capacity=50;
    int n=3;
    float ratio[n];

    float maxProfit=0;

    for(int i=0;i<n;i++){
        ratio[i]=profit[i]/wt[i];
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(ratio[i]<ratio[j]){
                float tempratio=ratio[i];
                ratio[i]=ratio[j];
                ratio[j]=tempratio;

                float temprofit=profit[i];
                profit[i]=profit[j];
                profit[j]=temprofit;

                float tempwt=wt[i];
                wt[i]=wt[j];
                wt[j]=tempwt;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(wt[i]<=capacity){
            maxProfit+=profit[i];
            capacity-=wt[i];
        }
        else{
            maxProfit+=ratio[i]*capacity;
            break;
        }
    }
    printf("Maximum profit: %.2f",maxProfit);
    return 0;
}