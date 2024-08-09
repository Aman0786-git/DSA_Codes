#include<stdio.h>

void merge(int arr[],int p,int q,int r){
    int n1=q-p+1;
    int n2= r-q;
    int l[n1],m[n2],i,j,k;

    for(i=0;i<n1;i++)
        l[i]=arr[i+p];
    for(j=0;j<n2;j++)
        m[j]=arr[j+q+1];

    i=j=0;
    k=p;
    while(i<n1 && j<n2){
        if(l[i]<=m[j]){
            arr[k++]=l[i++];
        }
        else
        arr[k++]=m[j++];
    }
    while(i<n1)arr[k++]=l[i++];
    while(j<n2)arr[k++]=m[j++];
}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
    }
}
int main()
{
    int arr[10]={9,8,3,4,10,11,2,5,3,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    printArr(arr,10);
    mergeSort(arr,0,9);
    printf("\n");
    printArr(arr,10);
    return 0;
}