#include<stdio.h>
#define MAX 100

void merge(int arr[],int low,int high,int mid){
    int temp[MAX];
    int i=low;
    int k=low;
    int j=mid+1;

    while (i<=mid && j<=high)
    {
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while (i<=mid){
        temp[k++]=arr[i++];
    }
    while (j<=high){
        temp[k++]=arr[j++];
    }

    for(int p=low;p<=high;p++){
        arr[p]=temp[p];
    }

}
void mergeSort(int arr[],int low,int high){
    if (low<high)
    {
        int mid=low+(high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);

        merge(arr,low,high,mid);
    }
    
}

int main(){
    int arr[]={38,27,43,3,9,82,10};
    int size=sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr,0,size-1);
    printf("Sorted Array: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}