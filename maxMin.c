#include<stdio.h>
int max,min;

void maxMin(int arr[],int low,int high){
    if(low==high){
        max=min=arr[low];
        return;
    }
    if(high==low+1){
        if(arr[low]>arr[high]){
            max=arr[low];
            min=arr[high];
        }
        else {
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
    if(max<max1) max=max1;
    if(min>min1) min=min1;
}
int main(){
    int arr[]={38,27,43,3,9,82,10,11};
    int size=sizeof(arr)/sizeof(arr[0]);

    maxMin(arr,0,size-1);
    printf("Maximum: %d\n",max);
    printf("Minimum: %d\n",min);

    return 0;
}