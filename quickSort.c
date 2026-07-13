#include<stdio.h>
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    int j=low;

    for(j;j<high;j++)
    {
        if(arr[j]<pivot){
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
        int temp=arr[i+1];
        arr[i+1]=arr[high];
        arr[high]=temp;

        return i+1;
    }

void quickSort(int arr[],int low,int high){
    if(low<high){
        int p=partition(arr,low,high);
        quickSort(arr,0,p-1);
        quickSort(arr,p+1,high);
    }
}
int main(){
    int arr[]={38,27,43,3,9,82,10};
    int size=sizeof(arr)/sizeof(arr[0]);

    quickSort(arr,0,size-1);
    printf("Sorted Array: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}