#include<stdio.h>

int binSearch(int arr[0],int n,int ele ){
    int low=0,mid,high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(ele==arr[mid])return mid;
        else if(ele<arr[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int main(){
    int i,arr[100],ele,size,index;
    printf("Enter Array Size: ");
    scanf("%d",&size);
    printf("Enter Elements: ");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter Element to be searched: ");
    scanf("%d",&ele);
    index= binSearch(arr,size,ele);
    if(index!=-1)printf("Element found at :%d",index);
    else
    printf("Element Not Found");
    return 0;
}