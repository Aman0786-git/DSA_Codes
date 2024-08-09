#include<stdio.h>

int partition(int arr[],int start,int end){
    int pivot=arr[end];
    int i=start-1;

    for(int j=start;j<end;j++){
        if(arr[j]<pivot){
            i++;
            int t = arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }
    }
    int t= arr[i+1];
    arr[i+1]=arr[end];
    arr[end]=t;
    return (i+1);
}

void quick(int arr[],int start,int end){
    if(start<end){
        int p= partition(arr,start,end);
        quick(arr,start,p-1);
        quick(arr,p+1,end);
    }
}
void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
       printf("%d ",arr[i]); 
    }
}

int main(){
    int arr[5]={19,2,1,8,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Array Before Sorting :\n");
    printArr(arr,n);
    quick(arr,0,n-1);
    printf("\nArray After Sorting :\n");
    printArr(arr,n);
    return 0;
}