#include <stdio.h>
int binarySearch(int arr[],int low,int high,int key){
    if(low>high){
        return -1;
    }
    int mid=low+(high-low)/2;
    if(arr[mid]==key) return mid;
    else if(arr[mid]<key){
        return binarySearch(arr,mid+1,high,key);
    }
    else{
        return binarySearch(arr,low,mid-1,key);
    }
}
int main(){
    int arr[]={4, 7, 9, 10, 15, 22, 32};
    int size=sizeof(arr)/sizeof(arr[0]);
    int key;

    printf("Enter the element to search: \n");
    scanf("%d",&key);

    int res=binarySearch(arr,0,size-1,key);
    if(res!=-1){
        printf("The key %d is found at index %d",key, res);
    }
    else{
        printf("The key is not found!");
    }
    return 0;
}