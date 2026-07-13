#include <stdio.h>
int binarySearch(int arr[],int low,int high,int key){
    while (low<=high)
    {
        /* code */
        int mid=low+(high-low)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            low=mid+1;
        }
        else {
            high=mid-1;
        }
            return -1;
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