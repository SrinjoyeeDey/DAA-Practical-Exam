#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int low,int high){
    int i=low-1,pivot=arr[high];
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

int randomizedPartition(int arr[],int low,int high){
    int random=low+rand()%(high-low+1);
    swap(&arr[random],&arr[high]);

    return partition(arr,low,high);
}

void randomQuickSort(int arr[],int low,int high){
    if(low<high){
        int pi=randomizedPartition(arr,low,high);
        randomQuickSort(arr,low,pi-1);
        randomQuickSort(arr,pi+1,high);
    }
}

int main(){
    srand(time(NULL));
    int arr[]={38,27,43,3,9,82,10,11};
    int size=sizeof(arr)/sizeof(arr[0]);

    randomQuickSort(arr,0,size-1);
    printf("Sorted Array: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}