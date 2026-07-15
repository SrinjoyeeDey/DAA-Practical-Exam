#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int arr[],int i,int n){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if (left<n && arr[left]>arr[largest])
    {
        largest=left;
    }

    if (right<n && arr[right]>arr[largest])
    {
        largest=right;
    }
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        heapify(arr,largest,n);
    }
    
}

void heapSort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,i,n);
    }
    for(int i=n-1;i>0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,0,i);
    }
}

int main(){
    int arr[]={38,27,43,3,9,82,10};
    int size=sizeof(arr)/sizeof(arr[0]);

    heapSort(arr,size);
    for(int i=0;i<size;i++){
        printf("%3d",arr[i]);
    }
    return 0;
}