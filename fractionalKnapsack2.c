#include<stdio.h>

void swapInt(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void swap(float *a,float *b){
    float temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
    int wt[]={10, 20, 30};
    int profit[]={60, 100, 120};
    int capacity=50;
    int n=3;

    float maxprofit=0;

    float ratio[n];

    for(int i=0;i<n;i++){
        ratio[i]=(float)profit[i]/wt[i];
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(ratio[i]<ratio[j]){
                swap(&ratio[i],&ratio[j]);
                swapInt(&wt[i],&wt[j]);
                swapInt(&profit[i],&profit[j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(wt[i]<=capacity){
            maxprofit+=profit[i];
            capacity-=wt[i];
        }
        else{
            maxprofit+=ratio[i]*capacity;
            break;
        }
    }
    printf("Maximum profit: %.2f\n",maxprofit);
    return 0;
}