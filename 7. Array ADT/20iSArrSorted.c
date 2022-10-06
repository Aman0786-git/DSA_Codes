#include<stdio.h>
#include<stdlib.h>
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
void swap(int *x,int *y)
{
    int temp ;
    temp=*x;
    *x=*y;
    *y=temp;
}
void InsertSort(struct Array *arr,int x)
{   int i=arr->length-1;
    if(arr->length== arr->size)
    return ;
    while (i>=0 && arr->A[i]>x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

int isSort(struct Array arr)
{   
    int i;
    for(i=0;i<arr.length-1;i++)
    if(arr.A[i]>arr.A[i+1])
    {
        return 0;
    }
    return 1;
}

void ReArrange(struct Array *arr)
{
    int i,j;
    i=0;
    j=arr->length-1;

    while(i<j)
    {
        while(arr->A[i]<0)i++;
        while(arr->A[j]>=0)j--;
        if(i<j)swap(&arr->A[i],&arr->A[j]);
    }

}
int main()
{
    struct Array arr= {{2,1,-3,6,-15,-7},10,6};
    // InsertSort(&arr,20);
/* 
   if(isSort(arr))
   printf("Array is Sorted");
   else
   printf("Array is not Sorted"); */
    
    ReArrange(&arr);
    display(arr);
    return 0;
}