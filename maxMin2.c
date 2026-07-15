#include<stdio.h>

int max,min;
void maxMin(int arr[],int low,int high){
    if(low==high){
        max,min=arr[low];
        return;
    }
    if(low+1==high){
        if(arr[low]>arr[high]){
            max=arr[low];
            min=arr[high];
        }
        else{
            max=arr[high];
            min=arr[low];
        }
        return;
    }

    int mid=low+(high-low)/2;
    maxMin(arr,low,mid);
    int max1=max;
    int min1=min;

    maxMin(arr,mid+1,high);
    if(max1>max) max=max1;
    if(min1<min) min=min1;

    return;
}

int main(){
    int arr[]={38,27,43,3,9,82,10,11};
    int size=sizeof(arr)/sizeof(arr[0]);
    maxMin(arr,0,size-1);

    printf("Maximum value: %d\n",max);
    printf("Minimum value: %d\n",min);

    return 0;
}