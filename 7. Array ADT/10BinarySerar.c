#include<stdio.h>
struct Array
{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr)
{
    int i;
    printf("\nElements are :\n");
    for(i=0;i<arr.length;i++)
    printf("%d ",arr.A[i]);
}
int binSearch(struct Array arr,int key)
{  
    int l,mid,h;
    l=0;
    h=arr.length-1;
    while (l<=h)
    {    mid=(l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
         h = mid-1;
         else
         l = mid+1;
        
    }
    
    return -1;
}

int BinSerRec(int a[],int l,int h,int key)
{
    int mid;
    if(l<=h)
    {
        mid=(l+h)/2;
        if(key==a[mid])
        return mid;
        else if(key<a[mid])
        return BinSerRec(a,l,mid-1,key);
        else 
        return BinSerRec(a,mid+1,h,key);
    }
    return -1;
}
int main()
{
   struct Array arr = {{2,3,4,5,6},10,5};
//    printf("%d\n",binSearch(arr,90));
   printf("%d\n",BinSerRec(arr.A,0,arr.length,9));
   display(arr);
   return 0;
}